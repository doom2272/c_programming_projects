/*
 * computes student's average and total grade for 5 quizes. Also computes the highest, lowest and average grade for each quiz.
 */

#include <stdio.h>

#define N 5

int main(void)
{
  int num[N][N] = {0}, rowSum[N] = {0}, colSum[N] = {0};


  printf("\nEnter grades for 5 different quizes for 5 students\n\t   q1 q2 q3 q4 q5\n");
  for ( int i = 0; i < N; i++) {
    printf("Student %d: ", i + 1); // prompts user digitts 5 times
    for ( int j = 0; j < N; j++) {
      scanf("%d", &num[i][j]); // the complete row is read and stored in 2D array
      rowSum[i] += num[i][j]; // the entire row is added
      colSum[j] += num[i][j]; // updates each column by only adding the columns, while on the same row, the numbers are not added, since j is always incrementing, it only adds when i increments
    }
  }

  printf("\nStudent\tTotal Grade  Average\n");
  for (int i = 0; i < N; i++) {
    printf("%4d %10d %8.2f",i + 1, rowSum[i], (float) rowSum[i] / N); //prints student number, their total grades, and the average
    printf("\n");
  }

  int max = 0, min = 0;

  printf("\nQuiz\tHighest grade  Lowest Grade  Average\n");
  for (int j = 0; j < N; j++) { // this loop compares all the columns to find the largest and lowest values
    max = num[0][j]; // the first column in each column is treated as both the highest and lowest value
    min  = num[0][j];
    for (int i = 1; i < N; i++) { //uses 2 if's to overwrite max and min in each column if there are values higher or lower than them. Important to note i start at 1 and not 0 becase we already have the first element stored in max and min. so we are comparing the current valuse with the previous one
      if (num[i][j] > max)
        max = num[i][j];
      if (num[i][j] < min)
        min = num[i][j];
    }
    printf("%4d %13d  %12d  %10.2f", j + 1, max, min, (float) colSum[j] / N);
    printf("\n");
  }

  putchar('\n');

  return 0;
}
