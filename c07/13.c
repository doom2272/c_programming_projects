/*
calculates the average word lenght for a sentence, displays average to one decimal place
*/

#include <stdio.h>

int main(void)
{
  float letter = 0.0f, word = 0.0f;
  char c;
  int edge = 0;//flag variable, looks to see whether were in a word or not, to avoid taking the second space after 2 spaces as a word

  printf("Enter a sentence: ");

  while ((c = getchar()) != '\n') {
    if (c == ' ') {
      edge = 0; //we are between words
    } else {
      if (edge == 0) {
        word++; //edge, we came from spaces and are at a first char of a word, so word++
        edge = 1; //set edge to 1 so that the next char is seen as part of the word already counted. If you dont do this it will be counted as another word, i.e word++.
      }
      letter++; //increment letter after each char is read, but doen't work for spaces.
    }
  }

  printf("Average word length: %.1f\n", letter / word);

  return 0;
}
