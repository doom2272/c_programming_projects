// modify sum2.c so that it now sums a series of double values.

#include <stdio.h>

int main(void)
{
  double n, sum = 0.0;

  printf("** this program sums a series of 'double' values. **\n");

  printf("\n Enter double value: (0 to terminate): ");
  scanf("%lf", &n);

  while (n != 0) {
    sum += n;
    scanf("%lf", &n);
  }

  printf("The sum is: %f\n", sum);// never use %lf in printf, but it can be used in scanf!

  return 0;
}
