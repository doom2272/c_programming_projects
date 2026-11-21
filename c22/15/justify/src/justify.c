/* Formats a text file.
 * both the file to be formatted and the file where the clean file is saved are
 * provided when running the program
 * */

#include "line.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: program input_file output_file\n");
    exit(EXIT_FAILURE);
  }

  FILE *in;
  if ((in = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  FILE *out;
  if ((out = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Cannot write to %s\n", argv[2]);
    fclose(in);
    exit(EXIT_FAILURE);
  }

  char word[MAX_WORD_LEN + 2];
  int word_len;

  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN + 1, in);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line(out);
      fclose(in);
      fclose(out);
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line(out);
      clear_line();
    }
    add_word(word);
  }
}
