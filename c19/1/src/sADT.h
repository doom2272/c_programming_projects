#ifndef SADT_H
#define SADT_H

#include <stdbool.h>

typedef struct stack_type Stack;

typedef char Item;

Stack *init_stack(void);
void destroy(Stack *s);
void make_empty(Stack *s);
bool is_empty(const Stack *s);
bool is_full(const Stack *s);
void push(Stack *s, Item i);
Item pop(Stack *s);

#endif
