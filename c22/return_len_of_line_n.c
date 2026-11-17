#include <stdio.h>

int line_length(const char *filename, int n) {
  if (n <= 0)
    return 0;

  FILE *fp;

  if ((fp = fopen(filename, "r")) == NULL)
    return 0;

  int current_line = 1, ch;
  while (current_line < n && (ch = fgetc(fp)) != EOF) {
    if (ch == '\n')
      current_line++;
  }

  int len = 0;
  while ((ch = fgetc(fp)) != EOF && ch != '\n')
    len++;

  fclose(fp);

  return len;
}
