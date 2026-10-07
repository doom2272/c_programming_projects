//solves RPN expressions, where operators come after operands. 
//eg 1 2 3 * + =  is interpreted as 1 + (2 * 3) = 
//this program expects single digit operands.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void)
{

  int result, operand1, operand2;
  int c;
  bool end = false;

  while (1) {

    printf("Enter 'q' to exit\nEnter an RPN expression: ");
    while ( !end && (c = getchar()) != EOF) {
      if (isdigit(c))
        push(c - '0');
      else {
        switch (c) {
          case 'q':
            exit(EXIT_SUCCESS);

          case '*': operand2 = pop(); operand1 = pop(); result = operand1 * operand2; push(result); break;
          case '/': operand2 = pop();
                    if (operand2 == 0) {
                      printf("Error: Division by 0!!\n");
                      exit(EXIT_FAILURE);
                    }
                    operand1 = pop(); result = operand1 / operand2; push(result); break;
          case '+': operand2 = pop(); operand1 = pop(); result = operand1 + operand2; push(result); break;
          case '-': operand2 = pop(); operand1 = pop(); result = operand1 - operand2; push(result); break;

          case ' ':
          case '\n': break;

          case '=': 
                     printf("Value of expression: %d \n", pop());
                     end = true;
                     break;

          default:
                     printf("Error: Invalid character %c\n", c);
                     exit(EXIT_FAILURE); break;

        }
      }
    }

    if (c != '\n' && c != EOF)
      while (getchar() != '\n')
        ;

    end = false;
    make_empty();
  }


}
