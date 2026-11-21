/* reads phone numbers from a file. the file has a single phone number in each
 * line. each phone number contains 10 digits, and other characters e.g ( . -
 * which should be ignored. displays the phone number in the form: (XXX)
 * XXX-XXXX
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_LEN 10

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: program source_filename\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp = NULL;
  int status = EXIT_FAILURE;

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Error: Cannot open %s\n", argv[1]);
    goto cleanup;
  }

  int ch, i = 0;
  char extracted_num[NUM_LEN + 1];
  while ((ch = getc(fp)) != EOF) {
    if (isdigit(ch))
      extracted_num[i++] = ch;

    if (i == NUM_LEN) {
      extracted_num[i] = '\0';
      printf("(%.3s) %.3s-%.4s\n", extracted_num, extracted_num + 3,
             extracted_num + 6);
      i = 0;
    }
  }

  if (ferror(fp)) {
    fprintf(stderr, "Error: Read error occured!!\n");
    goto cleanup;
  }

  status = EXIT_SUCCESS;

cleanup:
  if (fp != NULL)
    fclose(fp);
  return status;
}
