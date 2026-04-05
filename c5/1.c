/*
shows how many digits user input has, assume max is 4 digits.
*/

#include <stdio.h>

int main(void)
{
  int i, n;

  printf("Enter a number: ");
  scanf("%d", &i);

  if (0 <= i && i <= 9)
    n = 1;
  else if (10 <= i && i <= 99)
      n = 2;
  else if (100 <= i && i <= 999)
      n = 3;
  else if (1000 <= i && i <= 9999)
      n = 4;

  printf("The number %d has %d digits\n", i, n);

  return 0;
}
