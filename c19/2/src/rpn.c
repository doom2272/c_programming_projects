#include "rpnADT.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Stack *my_stack = init_stack();

  Item result, operand1, operand2;
  char c;
  bool end = false;

  while (1) {

    printf("Enter 'q' to exit\nEnter an RPN expression: ");
    while (!end && (scanf(" %c", &c)) == 1) {
      if (isdigit(c))
        push(my_stack, c - '0');
      else
        switch (c) {
        case 'q':
          exit(EXIT_SUCCESS);

        case '*':
          operand2 = pop(my_stack);
          operand1 = pop(my_stack);
          result = operand1 * operand2;
          push(my_stack, result);
          break;
        case '/':
          operand2 = pop(my_stack);
          operand1 = pop(my_stack);
          result = operand1 / operand2;
          push(my_stack, result);
          break;
        case '+':
          operand2 = pop(my_stack);
          operand1 = pop(my_stack);
          result = operand1 + operand2;
          push(my_stack, result);
          break;
        case '-':
          operand2 = pop(my_stack);
          operand1 = pop(my_stack);
          result = operand1 - operand2;
          push(my_stack, result);
          break;

        case ' ':;
          break;

        case '=':
          // 1. Pop the final answer first
          result = pop(my_stack);

          // 2. Check if there is leftover junk sitting underneath the answer
          if (!is_empty(my_stack)) {
            printf("Error: Too many operands (leftover junk)!\n");
            exit(EXIT_FAILURE); // Or break/continue depending on your plan
          }

          // 3. If the stack is perfectly empty, print the valid answer
          printf("Value of expression: %d \n", result);
          end = true;
          break;

        default:
          exit(EXIT_FAILURE);
          break;
        }
    }

    while (getchar() != '\n')
      ;

    end = false;
    make_empty(my_stack);
  }

  destroy(my_stack);
  return 0;
}
