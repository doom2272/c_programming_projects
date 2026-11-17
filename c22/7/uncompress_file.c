/* uses run-length decoding, replaces a sequence of;
 *    1. the repeatation count,
 *    2. the byte.
 *
 *    with a sequence of bytes
 *
 *    so 01 46   02 6F   03 20     01 61  becomes
 *        46    6F  6F  20 20 20    61
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: program filename\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp, *uncompressed;

  if ((fp = fopen(argv[1], "rb")) == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  size_t len = strlen(argv[1]);

  if (len <= 4 || (strcmp(*(argv + 1) + len - 4, ".rle")) != 0) {
    fprintf(stderr, "Only pass files with '.rle' extension to the program\n");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  char uncomp_filename[len - 3];

  snprintf(uncomp_filename, sizeof(uncomp_filename), "%s", argv[1]);

  if ((uncompressed = fopen(uncomp_filename, "wb")) == NULL) {
    perror("fopen");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  int count, byt;
  while ((count = getc(fp)) != EOF) {
    if ((byt = getc(fp)) == EOF) {
      if (ferror(fp)) {
        perror("getc");
        fclose(fp);
        fclose(uncompressed);
        exit(EXIT_FAILURE);
      }

      fclose(fp);
      fclose(uncompressed);
      exit(EXIT_FAILURE);
    }
    while (count--) {
      putc(byt, uncompressed);
    }
  }

  fclose(fp);
  fclose(uncompressed);

  return 0;
}
