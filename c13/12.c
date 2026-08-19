//prints sentence reversal.

#include <stdio.h>

#define WORDS_LEN 30
#define LETTER_LEN 20

int main(void)
{
  char stop = '.';
  char sentence[WORDS_LEN][LETTER_LEN+1];
  int c, row = 0, column, i;

  printf("Enter a sentence: ");

  c = getchar();
  while (row < WORDS_LEN && c != '\n') {

    while (c == ' ' || c == '\t')
      c = getchar();

    if (c == '\n')
      break;

    if (c == '.' || c == '?' || c == '!') {
      stop = (char)c;
      break;
    }

    column = 0;
    while(c != ' ' && c != '\t' && c != '!' && c != '?' && c != '.' && c != '\n'){
      if (column < LETTER_LEN)
        sentence[row][column++] = (char)c;

      c = getchar();
    }

    if (column > 0){
      sentence[row][column] = '\0';
      row++;
    }
  }

  for (i = row - 1; i >= 0; i--){
    printf("%s ", sentence[i]);
  }

  printf("\b%c\n", stop);

  return 0;
}
