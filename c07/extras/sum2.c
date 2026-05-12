//edit sum.c so that it can handle larger variables, higher than 32,767 (signed int)

#include <stdio.h>

int main(void)
{
  long n, sum = 0;

  printf("** this program sums a series of integers. **\n");

  printf("\n Enter integers (0 to terminate): ");
  scanf("%ld", &n);

  while (n != 0) {
    sum += n;
    scanf("%ld", &n);
  }

  printf("The sum is: %ld\n", sum);
}
