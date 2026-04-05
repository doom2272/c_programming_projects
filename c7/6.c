/*
program prints the values of sizeof for int, short, long, float, double & long double
*/

#include <stdio.h>

int main(void)
{
  printf("Byte size of int: %zu\n", sizeof(int));

  printf("Byte size of short: %zu\n", sizeof(short));

  printf("Byte size of long: %zu\n", sizeof(long));

  printf("Byte size of float: %zu\n", sizeof(float));

  printf("Byte size of double: %zu\n", sizeof(double));

  printf("Byte size of long double: %zu\n", sizeof(long double));

  return 0;
}
