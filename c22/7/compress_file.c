/* uses run-length encoding, replaces a sequence of identical byte a pair of
 * bytes:
 *    1. the repeatation count,
 *    2. the byte.
 *
 *    so  46    6F  6F  20 20 20    61   becomes,
 *       01 46   02 6F   03 20     01 61
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: program filename\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp, *compressed;

  if ((fp = fopen(argv[1], "rb")) == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  char comp_filename[strlen(argv[1]) + 5];
  snprintf(comp_filename, sizeof(comp_filename), "%s%s", argv[1], ".rle");

  if ((compressed = fopen(comp_filename, "wb")) == NULL) {
    perror("fopen");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  int prev_ch, ch, count;
  if ((prev_ch = getc(fp)) == EOF) {
    if (ferror(fp)) {
      perror("getc");
      fclose(fp);
      fclose(compressed);
      exit(EXIT_FAILURE);
    }

    fclose(fp);
    fclose(compressed);
    return 0;
  }

  count = 1;

  while ((ch = getc(fp)) != EOF) {
    if (ch != prev_ch || count == 255) {
      putc(count, compressed);
      putc(prev_ch, compressed);
      count = 1;
      prev_ch = ch;
    } else {
      count++;
    }
  }

  putc(count, compressed);
  putc(prev_ch, compressed);

  fclose(fp);
  fclose(compressed);

  return 0;
}
