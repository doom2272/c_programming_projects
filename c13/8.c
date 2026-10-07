
/*
 * program computes the value of a word enterd by user, i.e, SCRABBLE.
 * modified to include compute_scrabble_value function
 */

#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 40

int compute_scrabble_value(const char *word);

int main(void)
{
  char word[WORD_LEN];

  printf("Enter a word: ");
  scanf("%39s", word);//since our word array can hold 40 characters, "%39s" tells scanf to only populate a maximum of 39 charactes in the array, leaving room for the null character

  for (int i = 0; word[i] != 0; i++) { //exit if the input does not contains only letters
    if (!isalpha((unsigned char)word[i])) {
      printf("-- Input should be a valid word! --\n");
      return 1;
    }
  }

  printf("Scrabble value is: %d\n", compute_scrabble_value(word));

  return 0;
}

int compute_scrabble_value(const char *word)
{
  int sum = 0, value[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

  while (*word) {
    sum += value[toupper((unsigned char)*word) - 'A'];//converts each char in a string to upper case then subtracts 'A' from the letter/char, this difference is used to access the scrabble value of the letter from the value array.
    word++;
  }

  return sum;
}
