#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct Node {
  char *data;
  struct Node *next;
} Node;
typedef struct {
  Node *head;
} List;

List *create_list();
void append_list(List *l, char *v);
void free_list(List *l);
void print_list(List *l);

#endif
