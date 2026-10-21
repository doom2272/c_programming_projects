#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

#define STACK_SIZE 100

struct stack_type {
  Item *contents;
  Item top;
  Item size; //stores the stack's maximum size (length of the array contents points to)
};

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack *create(Item size) //now user needs to specify the length of the array when calling create
{
  Stack *s = malloc(sizeof(struct stack_type));
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  s->contents = malloc(size * sizeof(Item));
  if (s->contents == NULL) {
    free(s);
    terminate("Error in create: stack could not be created");
  }
  s->top = 0;
  s->size = size;

  return s;
}

void destroy(Stack *s)
{
  free(s->contents);
  free(s);
}

void make_empty(Stack *s)
{
  s->top = 0;
}

bool is_empty(Stack *s)
{
  return s->top == 0;
}

bool is_full(Stack *s)
{
      return s->top == s->size;
}

void push(Stack *s, Item i)
{
  if (is_full(s))
    terminate("Error in push: stack is full.");
  s->contents[s->top++] = i;
}

Item pop(Stack *s)
{
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");
  return s->contents[--s->top];
}
