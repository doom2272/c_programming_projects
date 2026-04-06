/*
 * checks a number for repeated digits.
 */

#include <stdio.h>
#include <stdbool.h> // sets false = 0 and true = 1

int main(void)
{
  bool digit_seen[10] = {false}; // all elements have value 0 now.
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10; // checks n from right to left
    if (digit_seen[digit]) { // if index digit in digit_seen[] is true exit loop
      break;
    }
    digit_seen[digit] = true; // otherwise change digit_seen[digit] from 0 to 1
    n /= 10;
  }

  if (n > 0)
    printf("Repeated digit\n");
  else 
    printf("No repeated digit\n");

  return 0;
}
