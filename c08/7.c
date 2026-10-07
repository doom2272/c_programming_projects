/*
 * reads a 5 * 5 array of int's and prints the rows & columns sum.
 */

#include <stdio.h>

#define N 5

int main(void)
{
  int num[N][N] = {0}, rowSum[N] = {0}, colSum[N] = {0};


  for ( int i = 0; i < N; i++) {
    printf("Enter row %d: ", i + 1); // prompts user digitts 5 times
    for ( int j = 0; j < N; j++) {
      scanf("%d", &num[i][j]); // the complete row is read and stored in 2D array
      rowSum[i] += num[i][j]; // the entire row is added
      colSum[j] += num[i][j]; // updates each column by only adding the columns, while on the same row, the numbers are not added, since j is always incrementing, it only adds when i increments
    }
  }

  printf("\nRow totals: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", rowSum[i]);
  }
  putchar('\n');

  printf("Column totals: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", colSum[i]);
  }
  putchar('\n');

  return 0;
}
