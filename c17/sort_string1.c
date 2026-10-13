//sorts a series of words.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LEN 20

char *words[MAX_WORDS];

int read_line(char str[], int n);

int main(void)
{
  int word = 0;

  for (;;) {
    printf("Enter word: ");

    char *str = malloc(MAX_WORD_LEN + 1);
    int len = read_line(str, MAX_WORD_LEN);

    if (len == 0 || word == MAX_WORD_LEN) {
      free(str);
      break;
    }

    words[word] = str;
    word++;
  }

  for (int i = 0; i < word - 1; i++) {
    for (int j = i + 1; j < word; j++) {
      if ((strcmp(words[i], words[j])) > 0) {
        char *temp = words[j];
        words[j] = words[i];
        words[i] = temp;
      }
    }
  }

  printf("\nIn sorted order: ");
  for (int i = 0; i < word; i++)
    printf("%s ", words[i]);

  putchar('\n');

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
