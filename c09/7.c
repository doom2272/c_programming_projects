/*
 * calculates a number x to powers n.
 */

#include <stdio.h>

long power(int x, int n)
{
  long temp;

  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    temp = power(x, n / 2);

    return temp * temp;
  }
  else 
    return x * power(x, n - 1);

}

int main(void)
{
  int x, n;

  printf("Enter x (base): ");
  scanf("%d", &x);

  printf("Enter n (exponent): ");
  scanf("%d", &n);

  printf("\n%d to the power of %d is %ld\n\n", x, n, power(x, n));

  return 0;
}
