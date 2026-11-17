// checks if you can open a file name provided at when running the program, for
// reading

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  bool fail_occured = false;

  if (argc < 2) {
    printf("usage: canopen filename\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      fail_occured = true;
      printf("%s can't be opened\n", argv[i]);
      continue;
    }

    printf("%s can be opened\n", argv[i]);
    fclose(fp);
  }

  if (fail_occured)
    exit(EXIT_FAILURE);

  return 0;
}
