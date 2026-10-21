#include "sADT.h"
#include <stdio.h>
#include <stdlib.h>

#define PUBLIC
#define PRIVATE static

struct node {
  Item data;
  struct node *next;
};

struct stack_type {
  struct node *top;
};

PRIVATE void terminate(const char *message) {
  printf("%s", message);
  exit(EXIT_FAILURE);
}

PUBLIC Stack *init_stack(void) {
  Stack *temp = malloc(sizeof(struct stack_type));

  if (temp == NULL)
    terminate("Err: failed at creating stack");

  Stack *s = temp;

  s->top = NULL;

  return s;
}

PUBLIC void destroy(Stack *s) {
  make_empty(s);

  free(s);
}

PUBLIC void make_empty(Stack *s) {
  while (!is_empty(s))
    pop(s);
}

PUBLIC bool is_empty(const Stack *s) { return s->top == NULL; }

PUBLIC bool is_full(const Stack *s) {
  (void)s;

  struct node *temp = malloc(sizeof(struct node));

  if (temp == NULL)
    return true;

  free(temp);
  return false;
}

PUBLIC void push(Stack *s, Item i) {

  if (is_full(s))
    terminate("Err: at push. Not enough space!!");

  struct node *new_node = malloc(sizeof(struct node));

  new_node->data = i;
  new_node->next = s->top;

  s->top = new_node;
}

PUBLIC Item pop(Stack *s) {
  if (is_empty(s))
    terminate("Err: stack is empty");

  struct node *old_top = s->top;

  Item value = s->top->data;

  s->top = s->top->next;
  free(old_top);

  return value;
}
