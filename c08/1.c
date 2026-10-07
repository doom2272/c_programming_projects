
/*
 * checks a number for repeated digits.
 */

#include <stdio.h>
#include <stdbool.h> // sets false = 0 and true = 1

int main(void)
{
  bool digit_seen[10] = {false}, repeated[10] = {false}; // all elements have value 0 now.
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10; // checks n from right to left
    if (digit_seen[digit])  // uses digit for indexing digit_seen, if element at said index is true, that means the number is repeated.
      repeated[digit] = true; //change the same index in the repeated[] array to true.
    digit_seen[digit] = true;// if its the first time seeing the number, change it value to true so that it will be considered a repeated number.
    n /= 10;

  }

  printf("Repeated digit(s): ");
  
  for (int i = 0; i < 10; i++) {
    if (repeated[i]) //if any element in repeated is true, that means it is a repeated number.
      printf("%d ", i);
  }

  printf("\n");

  return 0;
}
