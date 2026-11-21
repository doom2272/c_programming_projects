/*
 * formats, using tab, user input
 * reads input from a file and displays data in columns.
 *
 * lines in the file will have the form: item,price,mm/dd/yyyy
 */

#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 100

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: program filename\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;

  if ((fp = fopen(argv[1], "r")) == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  char line[LINE_LEN + 1];
  int item, m, d, y;
  float price;

  printf("\nItem\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\t\n");
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (sscanf(line, "%d,%f,%d/%d/%d", &item, &price, &m, &d, &y) == 5)
      printf("%-16d$%7.2f\t%d/%d/%d\n", item, price, m, d, y);
    else
      fprintf(stderr, "Line doesn't have the form 'item,price,mm/dd/yyyy'\n");
  }

  if (ferror(fp)) {
    perror("fgets");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  fclose(fp);

  return 0;
}
