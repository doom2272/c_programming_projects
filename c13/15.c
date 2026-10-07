//solves RPN expressions, where operators come after operands. 
//eg 1 2 3 * + =  is interpreted as 1 + (2 * 3) = 
//this program expects single digit operands.
//modifies the original project by adding the evaluate_RPN_expression function.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// external variables
int operands[STACK_SIZE];
int top = 0;

void make_empty(void) { top = 0; }

bool is_empty(void) {  return top == 0; }

bool is_full(void) {  return top == STACK_SIZE; }

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

int evaluate_RPN_expression(const char *expression);

int main(void)
{

  int i = 0, c;
  char expression[STACK_SIZE+1];

  printf("Enter 'q' to exit\nEnter and RPN expression: ");
  while ((c = getchar()) != '\n')//stores user input in expression[] to be passed to evaluate_RPN_expression.
    if (i < STACK_SIZE)
      expression[i++] = (char)c;
  expression[i] = '\0';

  printf("Value of expression: %d\n", evaluate_RPN_expression(expression));

  return 0;

}

int evaluate_RPN_expression(const char *expression)
{
  int result, operand1, operand2;

  while (*expression) {
    if (isdigit((unsigned char)*expression))
      push(*expression - '0');
    else {
      switch (*expression) {
        case 'q':
          exit(EXIT_SUCCESS);

        case '*': operand2 = pop();
                  operand1 = pop(); result = operand1 * operand2;
                  push(result);
                  break;
        case '/': operand2 = pop();
                  operand1 = pop();
                  result = operand1 / operand2;
                  push(result);
                  break;
        case '+': operand2 = pop(); 
                  operand1 = pop();
                  result = operand1 + operand2;
                  push(result); break;
        case '-': operand2 = pop();
                  operand1 = pop();
                  result = operand1 - operand2;
                  push(result);
                  break;
        case ' ': 
                  break;

        case '=': 
                  break;

        default:
                  printf("Invalid character: %c\n", *expression);
                  exit(EXIT_FAILURE);

      }
    }
    expression++;
  }

  int final_result = pop();

  make_empty();

  return final_result;
}
