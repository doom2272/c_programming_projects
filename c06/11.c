// program that expresses e (mathematical constant) as an infinite series useing factorial. eg user enters n, e = 1 + 1/1! + 1/2! + .... 1/n!.

#include <stdio.h>
int main(void)
{
  int n, i, j;
  float e = 1.0f, factorial = 1.0f;

  printf("** program approximates e by adding 1 / n!(factorial) upto user input (n terms) **\n");

  printf("\n Enter number of terms (n) for approximation: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    factorial *= i; //lets say user enters 3, i starts at 1 (factorial = 1 * 1 = 1), then i = 2 (factorial = 1 * 2 = 2), i = 3 (factorial = 2 * 3). Essentially factorial updates after each iteration. If you always start your multiplication at 1 you need 2 for loops. One for tracking i and the other for calculating the factorial of the current term! This uses nested loops and is less efficient than the method used here gives comp extra work.
    e += 1.0f / factorial;
  }

  printf("Approximation of e: %f\n", e);

}
