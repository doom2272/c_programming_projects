/*
 * reverses a series of number using a variable length array.
 */

#include <stdio.h>


int main(void)
{
  int i, n;

  printf("How many numbers do you want to reverse? ");
  scanf("%d", &n);

  int a[n]; //a is a variable length array. the length of a is computed when the program is executed not compiled.

  printf("Enter %d numbers: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("In reverse order: ");
  for (i = n - 1; i >= 0; i--)
    printf(" %d", a[i]);

  printf("\n");

  return 0;
}
