/*
 * prints a table to show how many times each digit appears from the users input.
 */

#include <stdio.h>

int main(void)
{
  int digit, occurrences[10] = {0};
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10; // checks n from right to left
    occurrences[digit]++; //increments elements each iteration(tracks occurrence of each digit)
    n /= 10; //shrinks number, ignores the one we just saw(furthest right digit)
  }

  printf("Digits:\t\t");
  for (int i = 0; i < 10; i++)
    printf("%d  ", i);

  putchar('\n');

  printf("Occurences:\t");
  for (int i = 0; i < 10; i++)
    printf("%d  ", occurrences[i]);

  putchar('\n');

  return 0;
}
