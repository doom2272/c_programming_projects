#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 100


int operands[STACK_SIZE];
int top = 0;

void make_empty(void)
{
  top = 0;
}


bool is_empty(void)
{
  return top == 0;
}


bool is_full(void)
{
  return top == STACK_SIZE;
}


void stack_underflow(void)
{
  printf("Not enough operands in expression!!\n");
  exit(EXIT_FAILURE);
}


void stack_overflow(void)
{
  printf("Expression is to complex!!!\n");
  exit(EXIT_FAILURE);
}


void push(int i)
{
  if (is_full())
    stack_overflow();
  else 
    operands[top++] = i;
}


int pop(void)
{
  if (is_empty()){
    stack_underflow();
    return -1;
  }
  else 
    return operands[--top];
}
