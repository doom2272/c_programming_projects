//sorts a series of words.
//now uses qsort to sort the array of pointers


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LEN 20

char *words[MAX_WORDS];

int read_line(char str[], int n);
int comparison_function(const void *p, const void *q);

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

  qsort(words, word, sizeof(words[0]), comparison_function);

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

int comparison_function(const void *p, const void *q)
{
  const char *p1 = *(const char **)p, *q1 = *(const char **)q;

  return strcmp(p1, q1);
}
