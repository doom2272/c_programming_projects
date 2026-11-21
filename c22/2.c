// converts all letters to uppercase in a file.
// file obtained from command line

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage: program filename\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "error: could not open %s \n", *(argv + 1));
    exit(EXIT_FAILURE);
  }

  int ch;
  while ((ch = fgetc(fp)) != EOF) {
    putchar(toupper(ch));
  }

  fclose(fp);

  return 0;
}
