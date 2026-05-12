/*
evaluates the following program:
expression: 1+2.5*3
result: 10.5

the operands are floating point numbers
operators are +, -, * and /
the expression is evaluated from left to right (no operator has precedence over another)
*/

#include <stdio.h>

int main(void)
{
  double num = 0.0, total = 0.0;
  char c;

  printf("Enter an expression: ");
  scanf("%lf", &total);

  while ((c = getchar()) != '\n') {
    if (c == ' ') continue;

    switch (c) {
      case '+':
      scanf("%lf", &num);
      total += num;
      break;
        case '-':
      scanf("%lf", &num);
      total -= num;
      break;
      case '*': 
      scanf("%lf", &num);
      total *= num;
      break;
        case '/': 
      scanf("%lf", &num);
      total /= num;
      break;
        default:
        printf("!! Invalid operator '%c' !!\n", c);
      break;
    }
  }

  printf("Value of the expression: %.2lf\n", total);

  return 0;
}
