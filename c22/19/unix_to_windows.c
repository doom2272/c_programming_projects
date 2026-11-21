/* converts UNIX text files to Windows.
 * UNIX uses \n for newline while Windows uses \r\n
 * this program changes that.
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
  while ((ch = getc(in_fp)) != EOF) {
    if (ch == '\n') {
      putc('\r', out_fp);
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
