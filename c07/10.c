/*
counts the number of vowels in a sentence;
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int vowels = 0, c;
  char d;

  printf("Enter a sentence: ");

  while ((c = getchar()) != '\n') {
    d = tolower((unsigned char)c);

    if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u')
      vowels++;
  }

  printf("Your sentence contains %d vowels.\n", vowels);

  return 0;
}
