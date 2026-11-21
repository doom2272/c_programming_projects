#include "word.h"
#include <ctype.h>
#include <stdio.h>

int read_char(FILE *stream) {
  int ch = getc(stream);

  return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

void read_word(char *word, int len, FILE *stream) {
  int ch, pos = 0;

  while ((ch = getc(stream)) != EOF && isspace(ch))
    ;
  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = ch;
    ch = read_char(stream);
  }
  word[pos] = '\0';
}
