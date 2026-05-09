#include <stdio.h>

double poly(double x);

int main(void)
{
  double x;

  printf("Enter the valuse of x: ");
  scanf("%lf", &x);

  printf("Value of polynomial: %.2f\n", poly(x));

  return 0;
}

double poly(double x)
{
  return (3 * (x * x * x * x * x)) + (2 * (x * x * x * x)) - (5 * (x * x * x)) - (x * x) + (7 * x) - 6;
}

