/*
adds two fractions, however doesn't display simplified fraction.
*/

#include <stdio.h>

int main(void)
{
  int num1, num2, den1, den2, num_sum, den_sum;

  printf("Enter two fraction separated by a plus sign: ");
  scanf("%d/%d+%d/%d", &num1, &den1, &num2, &den2);

  num_sum = num1 * den2 + num2 * den1;
  den_sum = den1 * den2;

  printf("The sum is %d/%d\n", num_sum, den_sum);

  return 0;
}
