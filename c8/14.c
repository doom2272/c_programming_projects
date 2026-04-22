/*
 * reverses words in a sentence. stores each character in an array. stops storing characters at . ? !
 */

#include <stdio.h>

#define N 50

int main(void)
{
  int i, end, start;
  char sentence[N] = {0}, stop = '.', c; // i initiallised stop to '.' incase the user forgets to end the sentence with the terminating character

  printf("Enter a sentence: ");

  for (i = 0; i < N; i++) { 
    c = getchar();

    if (c == '.' || c == '?' || c == '!') { // exit loop when we find any of the terminating characters
      stop = c;
      break;
    }

    sentence[i] = c; // otherwise store each char in sentence
  }

  for (int j = i - 1; j >= 0; j--) { //searches the user sentence backward
    while (j >= 0 && sentence[j] == ' ') j--; // skips over all spaces between words

    if (j < 0) break; // exits loop if we reach the first character

    end = j; //stores the position of the last char in our word

    while (j >= 0 && sentence[j] != ' ') //moves j to the start of the word, immesdiately after the space
      j--;

    start = j + 1; //stores the position of the start of the word

    for (int k = start; k <= end; k++) //prints the complete word
      putchar(sentence[k]);

    if (j > 0) putchar(' '); //inserts a space after each word except the first word

  }
  putchar(stop); // prints the terminating char if there was any, if there was none, automatically prints the ".", which we initiallised stop with at the begining

  putchar('\n');

  return 0;
}
