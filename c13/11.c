/*
 * calculates the average word length for a sentence, displays average to one decimal place.
 * modifies the program by using the function compute_average_word_length.
 */

#include <stdio.h>

#define SENTENCE_LEN 100

int read_line(char *s, int n);
double compute_average_word_length(const char *sentence);

int main(void)
{
  char sentence[SENTENCE_LEN];
  double average;

  printf("Enter a sentence: ");
  read_line(sentence, SENTENCE_LEN);

  average = compute_average_word_length(sentence);

  if (average > 0.0)
   printf("Average word length is %.1f\n", average);
  else 
    printf("-- You did not enter any word! --\n");


  return 0;
}

int read_line(char *s, int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n - 1)
      s[i++] = ch;
  s[i] = '\0';

  return i;
}

//counts the number of letters and words in a sentence to determine the average length of words.
double compute_average_word_length(const char *sentence)
{
  int letters = 0, words = 0, in_word = 0;

  while (*sentence){
    if (*sentence == ' ' || *sentence == '\t')
      in_word = 0;
    else {
      if (in_word == 0){
        words++;
        in_word = 1;
      }
      letters++;
    }
    sentence++;
  }

  if (words == 0)
    return .0;

  return (double)letters / words;
}
