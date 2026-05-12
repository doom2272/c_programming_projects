#include <stdbool.h>
#include <stdio.h>

bool check_perfect(int n);
int power(int base, int exp);
bool armstrong(int n);


int main(void)
{
  int x;

  printf("Enter a number: ");
  scanf("%d", &x);

  if (check_perfect(x))
    printf("%d is a perfect number\n", x);
  else 
    printf("%d is not a perfect number\n", x);

  if (armstrong(x))
    printf("%d is an Armstrong number\n", x);
  else 
    printf("%d is not an Armstrong number\n", x);

  return 0;
}

bool check_perfect(int n)
{
  int sum = 0;

  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }

  return sum == n;
}

int power(int base, int exp)
{
  if (exp == 0)
    return 1;

  return base * power(base, exp - 1);
}

bool armstrong(int n)
{
  int num = 0, temp = n, digit;
  long sum_p = 0;

  while (temp != 0) {
    temp /= 10;
    num++;
  }

  temp = n;

  while (temp != 0) {
    digit = temp % 10;

    int powered = 1;

    powered = power(digit, num);

    sum_p += powered;
    temp /= 10;
  }

  return sum_p == n;
}

