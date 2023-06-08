#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

List *create_list() {
  List *l = malloc(sizeof(List));
  if (l == NULL) {
    exit(EXIT_FAILURE);
  }
  l->head = NULL;
  return l;
}
void free_list(List *l) {
  Node *tmp = l->head;
  while (tmp) {
    Node *current = tmp;
    tmp = tmp->next;
    free(current);
  }
  free(l);
}
void append_list(List *l, char *v) {
  if (!l->head) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
      exit(EXIT_FAILURE);
    }
    n->data = v;
    n->next = NULL;
    l->head = n;
    return;
  }
  Node *tmp = l->head;
  while (tmp->next) {
    tmp = tmp->next;
  }
  Node *n = malloc(sizeof(Node *));
  if (n == NULL) {
    exit(EXIT_FAILURE);
  }
  n->data = v;
  n->next = NULL;
  tmp->next = n;
}

void print_list(List *l) {
  Node *tmp = l->head;
  while (tmp->next) {
    printf("%s->", tmp->data);
    tmp = tmp->next;
  }
  printf("%s->", tmp->data);
}
