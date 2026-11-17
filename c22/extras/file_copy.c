// copies a file

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  FILE *source_fp, *dest_fp;
  int ch;

  if (argc != 3) {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }

  if ((source_fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Could not open %s", argv[1]);
    fclose(source_fp);
    exit(EXIT_FAILURE);
  }

  if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Could not open %s\n", argv[2]);
    fclose(dest_fp);
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(source_fp)) != EOF) {
    int rr = putc(ch, dest_fp);

    if (rr == EOF) {
      fprintf(stderr, "error: Write error occured!!\n");
      fclose(source_fp);
      fclose(dest_fp);
      exit(EXIT_FAILURE);
    }
  }

  fclose(source_fp);
  fclose(dest_fp);

  return 0;
}
