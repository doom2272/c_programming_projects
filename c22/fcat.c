// concatenates files one after the other on screen

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "usage: fcat filename(s)\n");
    exit(EXIT_FAILURE);
  }

  bool problem = false;
  char buffer[BUFSIZ];
  FILE *fp;

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "rb")) == NULL) {
      fprintf(stderr, "error: can't open %s \n", argv[i]);
      problem = true;
      continue;
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
      fwrite(buffer, 1, bytes_read, stdout);
    }

    fclose(fp);
  }

  if (problem)
    exit(EXIT_FAILURE);

  return 0;
}
