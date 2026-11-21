// display contents of a file as bytes and characters

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: program filename\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;

  if ((fp = fopen(argv[1], "rb")) == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  unsigned char buffer[10];
  int i, n, offset;
  printf("Offset               Bytes             Characters\n");
  printf("------  -----------------------------  ----------\n");

  for (offset = 0;; offset += 10) {
    n = fread(buffer, 1, 10, fp);
    if (n == 0)
      break;

    printf("%6d  ", offset);
    for (i = 0; i < n; i++)
      printf("%.2X ", buffer[i]);

    for (; i < 10; i++)
      printf("   ");

    printf("  ");

    for (i = 0; i < n; i++) {
      if (!isprint(buffer[i]))
        buffer[i] = '.';
      printf("%c", buffer[i]);
    }
    putchar('\n');
  }

  fclose(fp);

  return 0;
}
