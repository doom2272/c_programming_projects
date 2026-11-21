// merges 2 files containing parts (files from project 8.c cap 22)
// assumes parts are sorted by part number, and the merge also sorts the parts.
// Looks at parts with the same part number: if
/*        1. different - prints error for that part,
 *        2. same - merges the two part, outputs a single part.
 *both the files to be merged plus the result file after the merge are obtained
 * from the command line.
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "usage: program file1 file2 merged_file\n");
    exit(EXIT_FAILURE);
  }

  FILE *f1, *f2, *merged;
  int num_read1, num_read2;
  struct part part1, part2;

  if ((f1 = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((f2 = fopen(argv[2], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(f1);
    exit(EXIT_FAILURE);
  }

  if ((merged = fopen(argv[3], "wb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[3]);
    fclose(f1);
    fclose(f2);
    exit(EXIT_FAILURE);
  }

  num_read1 = fread(&part1, sizeof(struct part), 1, f1);
  num_read2 = fread(&part2, sizeof(struct part), 1, f2);

  while (num_read1 == 1 && num_read2 == 1) {
    if (part1.number < part2.number) {
      fwrite(&part1, sizeof(struct part), 1, merged);

      num_read1 = fread(&part1, sizeof(struct part), 1, f1);
    } else if (part1.number > part2.number) {
      fwrite(&part2, sizeof(struct part), 1, merged);

      num_read2 = fread(&part2, sizeof(struct part), 1, f2);
    } else {
      if (strcmp(part1.name, part2.name) != 0)
        fprintf(stderr, "Names don't match for part %d: using the name %s\n",
                part1.number, part1.name);

      part1.on_hand += part2.on_hand;

      fwrite(&part1, sizeof(struct part), 1, merged);

      num_read1 = fread(&part1, sizeof(struct part), 1, f1);
      num_read2 = fread(&part2, sizeof(struct part), 1, f2);
    }
  }

  while (num_read1 == 1) {
    fwrite(&part1, sizeof(struct part), 1, merged);
    num_read1 = fread(&part1, sizeof(struct part), 1, f1);
  }

  while (num_read2 == 1) {
    fwrite(&part2, sizeof(struct part), 1, merged);
    num_read2 = fread(&part2, sizeof(struct part), 1, f2);
  }

  fclose(f1);
  fclose(f2);
  fclose(merged);

  return 0;
}
