//use array of pointer instead of switch statement to print the word version of a two digit number entered by user.

#include <stdio.h>

int main(void)
{ //some indexs have empty strings so that the math matches eg tens[2] is twenty
  char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  int digit;

  printf("Enter a two-digit number: ");
  scanf("%d", &digit);

  if (digit < 10 || digit > 99) {
    printf("-- !! Digit is out of range 10-99 !! --\n");
    return 1;
  }

  if((digit / 10) == 1)
    printf("You entered %s\n", teens[digit%10]);
  else
   printf("You entered %s-%s\n", tens[digit/10], ones[digit%10]);

  return 0;
}
