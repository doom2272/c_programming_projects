
/* reads ints from a txt file provided at the command line.
 * each line may contain zero or any number of intergers separated by one or
 * more spaces. assumes file contains no more than 10,000 ints. outputs: Largest
 * number, Smallest number, and Median. (average of middle 2 ints (rounded down)
 * if number of intergers is even)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10000

int compare_ints(const void *p, const void *q);

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

  int nums[MAX_NUMS], i = 0, read, n = 0;
  while (i < MAX_NUMS && (read = fscanf(fp, "%d", &n)) != EOF) {
    if (read == 0) {
      fprintf(stderr,
              "Error: non interger character encountered!!!\nEXITING..\n");
      goto cleanup;
    }

    nums[i++] = n;
  }

  if (i == 0) {
    fprintf(stderr, "File is empty\n");
    status = EXIT_SUCCESS;
    goto cleanup;
  }

  qsort(nums, i, sizeof(nums[0]), compare_ints);

  if (ferror(fp)) {
    fprintf(stderr, "Error: Read error occured!!\n");
    goto cleanup;
  }

  int largest = nums[i - 1], smallest = *nums, middle = i / 2,
      median = nums[middle];

  if ((i % 2) == 0) {
    median = nums[middle - 1] + (nums[middle] - nums[middle - 1]) / 2;
  }

  printf("Largest int: %d\nSmallest int: %d\nMedian: %d\n", largest, smallest,
         median);

  status = EXIT_SUCCESS;

cleanup:
  if (fp != NULL)
    fclose(fp);
  return status;
}

int compare_ints(const void *p, const void *q) {
  const int *p1 = p;
  const int *q1 = q;

  if (*p1 < *q1)
    return -1;
  else if (*p1 > *q1)
    return 1;
  else
    return 0;
}
