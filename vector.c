
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INITIAL_CAPACITY 10

void vector_resize(Vector *vector) {
  (vector->vector_resize)++;

  void **items =
      realloc(vector->data, VECTOR_INITIAL_CAPACITY * sizeof(void **) *
                                vector->vector_resize);
  if (items) {
    vector->data = items;
  }
}

Vector *vector_create() {
  Vector *v = (Vector *)malloc(sizeof(Vector));
  v->data = (void **)malloc(sizeof(void **) * VECTOR_INITIAL_CAPACITY);
  v->vector_resize = 0;
  return v;
}

void vector_push(Vector *vector, void *data) {
  if (vector->length % VECTOR_INITIAL_CAPACITY == 0) {
    vector_resize(vector);
  }
  vector->data[vector->length++] = data;
}

void destroy_vector(Vector *vector) { free(vector); }

void *vector_get(Vector *vector, int index) {
  if (index >= vector->length || index < 0) {
    return NULL;
  }
  return vector->data[index];
}

void *vector_pop(Vector *vector) {
  void *data = vector_get(vector, vector->length--);
  return data;
}
