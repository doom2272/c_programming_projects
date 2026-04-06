/*
 * prints a table of compound interest
 */

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0]))) //controls 2 for loops, when size of array value is changed to anything else, loops adjust normally.
#define INITIAL_BALANCE 100.00

int main(void)
{
  int i, low_rate, num_years, year;
  double value[5];

  printf("Enter the intrest rate: ");
  scanf("%d", &low_rate);
  printf("Enter thr number of years: ");
  scanf("%d", &num_years);

  printf("\nYears");
  for (i = 0; i < NUM_RATES; i++) { // prints the 5 different intrest rates at the top row
    printf("%6d%%", low_rate + i);
    value[i] = INITIAL_BALANCE;
  }
  printf("\n");

  for (year = 1; year <= num_years; year++) { // prints year and \n line after inner loop is complete
    printf("%3d    ", year);
    for (i = 0; i < NUM_RATES; i++) { // calculates the values + intrest for the different intrest rates.
      value[i] += (low_rate + i) / 100.00 * value[i]; //this line stores the different values for different years and only replace them when year is incremented. the value is calculated using the same intrest rate though.
      printf("%7.2f", value[i]);
    }
    printf("\n");
  }

  return 0;
}
