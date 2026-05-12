/*
 * checks multiple numbers (30 different numbers) for repeated digits.
 */

#include <stdio.h>
#include <stdbool.h> 

#define SIZE 30

int main(void)
{
  bool digit_seen[10] = {false};
  int a[SIZE] = {0}, count = 0, digit;
  long n;
  char next;

  printf("Enter multiple numbers: ");

  while (count < SIZE) { //reads multiple numbers
    scanf("%ld", &n);

    if (n <= 0) //program terminates if a number is less than or equal to 0
      return 1;

    a[count] = (int)n; // if number is larger than 0, its stored in a[] which hold the user's different numbers as elements
    count++;

    scanf("%c", &next);
    if (next == '\n') //check for end of user input
      break;
  }

  bool has_repeated;

  for (int i = 0; i < count; i++) { // iterates through all the user numbers
    has_repeated = false; //flag variable
    int temp = a[i]; //since we are using value at a[i] later, we don't want to overwrite it

    for (int j = temp; j > 0; j /= 10) { // iterates through all the digits in each number
      digit = j % 10; // check the furthest right digit first
      if (digit_seen[digit]) { // if digit_seen is true, that means its a repeated digit, so exit this inner loop
        has_repeated = true; // change our flag, used to print message below
        break;
      }
      digit_seen[digit] = true; //if number is seen for the first time, change its value so that next time its recognized as a repeated digit
    }

    if (has_repeated) //uses our flag variable to print
      printf("Repeated digit(s) in %d\n", a[i]);
    else 
      printf("No repeated digit.\n");

    for (int k = 0; k < 10; k++) { //this loop resets the digit_seen, so that each number from the user's input is treated as a fresh start
      digit_seen[k] = false;
    }
  }

  return 0;
}
