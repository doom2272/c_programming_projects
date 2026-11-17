// counts no. of words in a text file

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: program filename\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "error: can't open %s \n", argv[1]);
    exit(EXIT_FAILURE);
  }

  bool in_word = false;
  int ch;
  size_t word_count = 0;
  while ((ch = fgetc(fp)) != EOF) {
    if (isspace((unsigned char)ch))
      in_word = false;
    else if (!in_word) {
      in_word = true;
      word_count++;
    }
  }

  printf("Total words in %s : %zu\n", argv[1], word_count);

  fclose(fp);

  return 0;
}
