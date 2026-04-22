/*
 * finds anagrams. word that the same letters. eg smartest and mattress\
 */

#include <stdio.h>
#include <ctype.h>

#define N 26

int main(void)
{
  int letter[N] = {0};
  char c;

  printf("Enter the first word: ");
  while ((c = getchar()) != '\n') {// reads first word char by char upto newline char
    c = tolower(c); //converts char to lower

    if (isalpha(c)) letter[c - 'a']++; //if char is a letter, element representing the char in letter[] is incremented
  }

  printf("Enter the second word: ");
  while ((c = getchar()) != '\n') { //reads the second word
    c = tolower(c);

    if (isalpha(c)) letter[c - 'a']--; //decrements element representing char in letter[],which effectively tells us this letter is the same in both words
  }
  putchar('\n');

  
  int match = 1; // flag variable

  for (int j = 0; j < N; j++) {
    if (letter[j] != 0) { //if any element in the array is not zero, that means the letter was not found in both word
      match = 0; //set our flag to zero, to indicate we found found a letter that is unique to either word
      break; //exit loop
    }
  }

  if (match == 1) printf("The words are anagrams.\n"); //only if our flag is 1 and the loop above completed did we get an anagram
  else printf("The words are not anagrams. \n");

  return 0;
}
