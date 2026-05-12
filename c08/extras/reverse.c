/*
 * asks user to enter a series of numbers then prints the numbers in reverse.
 */

#include <stdio.h>

#define N 10 // very important to see how useful macros are when used with arrays. if at any time you want to change the size of the array a, simply change this macro.

int main(void)
{
  int a[N], i;

  printf("Enter %d numbers: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  printf("In reverse order: ");
  for (i = N - 1; i >= 0; i--)
    printf(" %d", a[i]);

  printf("\n");

  return 0;
}
