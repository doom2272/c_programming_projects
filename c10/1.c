#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// external variables
char contents[STACK_SIZE];
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
  printf("Stack underflow!!\n");
  exit(EXIT_FAILURE);
}


void stack_overflow(void)
{
  printf("Stack overflow!!!\n");
  exit(EXIT_FAILURE);
}


void push(char i)
{
  if (is_full())
    stack_overflow();
  else 
    contents[top++] = i;
}


int pop(void)
{
  if (is_empty()){
    stack_underflow();
    return -1;
  }
  else 
    return contents[--top];
}


int main(void)
{
  
  char c;

  printf("Enter parentheses and/or braces: ");
  while ((scanf("%c", &c)) == 1) {
    if (c == '\n')
      break;

    if (c != '{' && c != '}' && c != '(' && c != ')') {
      printf("\nOnly enter parentheses, (), or braces, {}.\n\n");
      return 1;
    }

    if (c == '(' || c == '{') {
      push(c);
    }

    if (c == ')' || c == '}') {
      int temp = pop();

      if (!((temp == '(' && c == ')') || (temp == '{' && c == '}')))
        break;
    }
  }

  if (top == 0 && c == '\n')
    printf("\nParentheses/braces are nested properly\n\n");
  else 
    printf("\nParentheses/braces are NOT nested properly!!!\n\n");
}
