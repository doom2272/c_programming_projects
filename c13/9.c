
/*
 * counts the number of vowels in a sentence.
 * modifies the program by adding the compute_vowel_count function
*/

#include <stdio.h>
#include <ctype.h>

#define SENTENCE_LEN 200

int compute_vowel_count(const char *sentence);
int read_line(char *s, int n);

int main(void)
{
  char sentence[SENTENCE_LEN];

  printf("Enter a sentence: ");
  read_line(sentence, SENTENCE_LEN);

  printf("Your sentence contains %d vowels.\n",compute_vowel_count(sentence));

  return 0;
}

//function returns the number of vowels in a sentence
int compute_vowel_count(const char *sentence)
{
  int vowels = 0;

  while (*sentence){
    char c = tolower((unsigned char)*sentence);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      vowels++;
  
  sentence++;
  }

  return vowels;
}

//function reads user input upto the \n, newline character
int read_line(char *s, int n)
{
  int ch, i = 0;

  while((ch = getchar()) != '\n')
    if(i < n - 1)
      s[i++] = ch;
  s[i] = '\0';

  return i;
}
