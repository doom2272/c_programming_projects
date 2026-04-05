// rewrite square3.c by intializing i, testing i, and incrementing i.

#include <stdio.h>

int main(void)
{
  int i, n, odd ,square;

  printf("This program prints a table of squares.\n");

  printf("Enter number of entires in table: ");
  scanf("%d", &n);

  odd = 3;
  for (i = 1, square = 1; i <= n; i++, odd += 2) {
    printf("%10d%10d\n", i, square);
    square += odd;
  }
}
