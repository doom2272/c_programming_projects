#include "sADT.h"
#include <stdio.h>

int main(void) {
  Stack *my_stack = init_stack();

  Item c;

  printf("Enter parentheses and/or braces: ");
  while ((scanf("%c", &c)) == 1) {
    if (c == '\n')
      break;

    if (c != '{' && c != '}' && c != '(' && c != ')') {
      printf("\nErr: Only enter parentheses, (), or braces, {}!!!\n\n");
      destroy(my_stack);
      return 1;
    }

    if (c == '(' || c == '{') {
      push(my_stack, c);
    }

    if (c == ')' || c == '}') {
      if (is_empty(my_stack)) {
        printf("\nParentheses/braces are NOT nested properly!!!\n\n");
        return 0;
      }

      int temp = pop(my_stack);

      if (!((temp == '(' && c == ')') || (temp == '{' && c == '}')))
        break;
    }
  }

  if (is_empty(my_stack) && c == '\n')
    printf("\nParentheses/braces are nested properly\n\n");
  else
    printf("\nParentheses/braces are NOT nested properly!!!\n\n");

  destroy(my_stack);
  return 0;
}
