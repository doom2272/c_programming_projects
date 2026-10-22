#include "stackADT.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PRIVATE static

struct node {
  Item data;
  struct node *next;
};

struct stack_type {
  struct node *top;
  int len;
};

PRIVATE void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack *create(void) {
  Stack *s = malloc(sizeof(struct stack_type));
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  s->top = NULL;
  s->len = 0;
  return s;
}

int length(Stack *s) { return s->len; }

void destroy(
    Stack *s) // calls make_empty to release memory occupied by node beofer it
              // calls free to release the memory for the stack_type structure.
{
  make_empty(s);
  free(s);
}

void make_empty(Stack *s) {
  while (!is_empty(s))
    pop(s);
}

bool is_empty(const Stack *s) { return s->top == NULL; }

bool is_full(const Stack *s) {

  (void)s;

  struct node *tmp = malloc(sizeof(struct node));

  if (tmp == NULL)
    return true;

  free(tmp);
  return false;
}

void push(Stack *s, Item i) {

  if (is_full(s))
    terminate("Err: failure at push, not enough memory!");

  struct node *new_node = malloc(sizeof(struct node));

  new_node->data = i;
  new_node->next = s->top;
  s->top = new_node;
  s->len++;
}

Item pop(Stack *s) {
  struct node *old_top;
  Item i;

  if (is_empty(s))
    terminate("Error in pop: stack is empty.");

  old_top = s->top;
  i = old_top->data;
  s->top = old_top->next;
  s->len--;
  free(old_top);
  return i;
}
