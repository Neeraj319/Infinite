#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct {
  int length;
  void **data;
  int vector_resize;
} Vector;

Vector *vector_create();
void destroy_vector(Vector *vector);
void vector_push(Vector *vector, void *data);
void *vector_pop(Vector *vector);
void *vector_get(Vector *vector, int index);

#endif
