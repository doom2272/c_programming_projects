
/*
 * uses Ceasar cipher to encrypt message. shifts letters according to user specification.
 */

#include <ctype.h>
#include <stdio.h>

#define N 80

void encrypt(char *message, int shift);

int main(void)
{
  int shift, i = 0, c;
  char mess[N] = {'0'};

  printf("Enter message to be encrypted: ");
  while ((c = getchar()) != '\n') //reads input stores it in mess[]
    if (i < N - 1)
      mess[i++] = (char)c;

  mess[i] = '\0'; //adds a null char at the end of mess[] to make it a valid string

  printf("Enter shift ammount : ");
  if ((scanf("%d",  &shift)) != 1) { //check to ensure shift is a number
    printf("-- Invalid number input! --\n");
    return 1;
  }

  encrypt(mess, shift);

  printf("Encrypted message: %s\n", mess);

  return 0;
}

void encrypt(char *message, int shift)
{
  shift = (shift % 26 + 26) % 26; //doesn't matter what number the user enters, shift will always range from 0 - 25, i.e, the alphabet range.

  while (*message) {
    if (isupper((unsigned char)*message))
      *message = ((*message - 'A') + shift) % 26 + 'A';
    else if (islower((unsigned char)*message))
      *message = ((*message - 'a') + shift) % 26 + 'a';

    message++;
  }
}
