//compares words, determines which comes first and last if listed in dictonary order.
//quits when user enters a 4 letter word/string

#include <stdio.h>
#include <string.h>

#define N 20

void read_line(char str[], int n);

int main(void)
{
  char input[N+1], smallest_word[N+1], largest_word[N+1];

  printf("Enter word: ");
  read_line(input, N);
  strcpy(smallest_word, strcpy(largest_word, input));

  while (strlen(input) != 4){
    printf("Enter word: ");
    read_line(input, N);

    if (strcmp(input, smallest_word) < 0)
      strcpy(smallest_word, input);
    if (strcmp(input, largest_word) > 0)
      strcpy(largest_word, input);
  }

  printf("\nSmallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);

  return 0;

}

void read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
}
