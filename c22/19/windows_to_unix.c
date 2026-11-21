/* converts windows text files to UNIX.
 * windows uses \r\n for newline while UNIX uses \n
 * this program changes that.
 * also legacy Windows/DOS used '\x1a' (Ctrl+z) for End-of-file. This program
 * also checks that.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int status = EXIT_FAILURE;

  if (argc != 3) {
    fprintf(stderr, "usage: program input_file output_file\n");
    exit(status);
  }

  FILE *in_fp = NULL, *out_fp = NULL;

  if ((in_fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    goto cleanup;
  }

  if ((out_fp = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[2]);
    goto cleanup;
  }

  int ch;
  while ((ch = getc(in_fp)) != '\x1a' && ch != EOF) {
    if (ch == '\r') {
      int next_ch = getc(in_fp);

      if (next_ch != '\n') {
        putc(ch, out_fp);
        ungetc(next_ch, in_fp);
        continue;
      }

      ch = next_ch;
    }

    putc(ch, out_fp);
  }

  if (ferror(in_fp)) {
    fprintf(stderr, "Read error occured!!\n");
    goto cleanup;
  }

  if (ferror(out_fp)) {
    fprintf(stderr, "Write error occured!!\n");
    goto cleanup;
  }

  status = EXIT_SUCCESS;

cleanup:
  if (in_fp != NULL)
    fclose(in_fp);
  if (out_fp != NULL)
    fclose(out_fp);
  return status;
}
