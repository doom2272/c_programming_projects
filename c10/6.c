
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// external variables
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


int main(void)
{

  int result, operand1, operand2;
  char c;
  bool end = false;

  while (1) {

    printf("Enter 'q' to exit\nEnter an RPN expression: ");
    while ( !end && (scanf(" %c", &c)) == 1) {
      if (isdigit(c))
        push(c - '0');
      else 
        switch (c) {
          case 'q':
            exit(EXIT_SUCCESS);

          case '*': operand2 = pop(); operand1 = pop(); result = operand1 * operand2; push(result); break;
          case '/': operand2 = pop(); operand1 = pop(); result = operand1 / operand2; push(result); break;
          case '+': operand2 = pop(); operand1 = pop(); result = operand1 + operand2; push(result); break;
          case '-': operand2 = pop(); operand1 = pop(); result = operand1 - operand2; push(result); break;

          case ' ': ; break;

          case '=': 
                    printf("Value of expression: %d \n", pop());
                    end = true;
                    break;

          default:
                    exit(EXIT_FAILURE); break;

        }

    }

    while (getchar() != '\n')
      ;

    end = false;
    make_empty();
  }


}
