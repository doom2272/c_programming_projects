
/*
 * now uses functions.
 * finds anagrams. word that the same letters. eg smartest and mattress\
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#define N 26

void read_word(int counts[26]);

bool equal_array(int counts[26], int counts2[26]);

int main(void)
{
  int letters[N] = {0}, letters2[N] = {0};

  printf("Enter the first word: ");

  read_word(letters);


  printf("Enter the second word: ");

  read_word(letters2);

  if (equal_array(letters, letters2))
    printf("The words are anagrams.\n");

  else 
    printf("The words are not anagrams. \n");

  return 0;
}


void read_word(int counts[26])
{

  char c;

  while ((c = getchar()) != '\n') {// reads first word char by char upto newline char
    c = tolower(c); //converts char to lower

    if (isalpha(c)) counts[c - 'a']++; //if char is a letter, element representing the char in letter[] is incremented
  }

}

bool equal_array(int counts[26], int counts2[26])
{
  for (int i = 0; i < N; i++) {
    if (counts[i] != counts2[i])
      return false;
  }

  return true;
}
