// calculates the length of a message; length includes spaces and punctuation but not \n

#include <stdio.h>

int main(void)
{
 /* first way of writing the program
  char ch;
  int len = 0;

  printf("Enter a message: ");
  ch = getchar();
  while (ch != '\n') {
    len++;
    ch = getchar();
  }

  printf("Your message was %d character(s) long.\n", len);
  */

  // more concise way of writing the program using idiom
  int len = 0;

  printf("Enter a message: ");
  while (getchar() != '\n')
    len++;
  printf("Your message was %d character(s) long.\n", len);

}
