// modifies the xor program in chapter 20.
// now the original/encrypted files are provided on the command line

#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char **argv) {

  if (argc != 3) {
    fprintf(stderr, "usage: program input_file output_file\n");
    exit(EXIT_FAILURE);
  }

  FILE *in, *out;

  if ((in = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "can't open %s \n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((out = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "can't open %s \n", argv[2]);
    fclose(in);
    exit(EXIT_FAILURE);
  }

  int orig_char, new_char;

  while ((orig_char = getc(in)) != EOF) {
    new_char = orig_char ^ KEY;

    if (putc(new_char, out) == EOF) {
      perror("putc");
      fclose(in);
      fclose(out);
      exit(EXIT_FAILURE);
    }
  }

  fclose(in);
  fclose(out);

  return 0;
}
