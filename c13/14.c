
/*
 * finds anagrams. word that have the same letters. eg smartest and mattres
 * add the function are_anagrams.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define N 26
#define WORD_LEN 40

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
  int i = 0;
  int c;
  char word1[WORD_LEN+1], word2[WORD_LEN+1];

  printf("Enter the first word: ");
  while ((c = getchar()) == ' ' || c == '\t') //skips leading spaces if any exist
    ;

  while (i < WORD_LEN && c != ' ' && c != '\t' && c != '\n') { //only stores a char if its a letter. if its a letter its first converted to uppercase before being saved.
    if (isalpha((unsigned char)c))
      word1[i++] = (char)toupper((unsigned char)c);
    c = getchar();
  }
  word1[i] = '\0';

  i = 0;

  putchar('\n');

  printf("Enter the second word: ");
  while ((c = getchar()) == ' ' || c == '\t')
    ;

  while (i < WORD_LEN && c != ' ' && c != '\t' && c != '\n') {
    if (isalpha((unsigned char)c))
      word2[i++] = (char)toupper((unsigned char)c);
    c = getchar();
  }
  word2[i] = '\0';

  putchar('\n');



  if (are_anagrams(word1, word2))
    printf("The words are anagrams.\n");
  else
    printf("The words are not anagrams. \n");

  return 0;
}


bool are_anagrams(const char *word1, const char *word2)
{
  int alphabets[N] = {0}, i = 0;

  if (strlen(word1) != strlen(word2)) //checks if the words have the same length
    return false;

  while (*word1) { //increments and decrements elements in alphabets array, which represents the alphabets (0 is A and 25 is Z). only if a letter exists in both word1 and word2 will its corresponding element in alphabets be zero.
    alphabets[*word1-'A']++;
    alphabets[*word2-'A']--;
    word1++;
    word2++;
  }


  while (i < N){
    if (alphabets[i])
      return false;
    i++;
  }

  return true;
}
