// counts no. of characters in a text file

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

  int ch;
  size_t char_count = 0;
  while ((ch = fgetc(fp)) != EOF)
    char_count++;

  printf("Total characters in %s : %zu\n", argv[1], char_count);

  fclose(fp);

  return 0;
}
