
/*
 * prints a table of compound interest, using monthly intrest not annual.
 */

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0]))) 
#define INITIAL_BALANCE 100.00
#define M 12 //used to calculate intrest monthly

int main(void)
{
  int i, low_rate, num_years, year;
  float rate;
  double value[5];

  printf("Enter the intrest rate: ");
  scanf("%d", &low_rate);
  printf("Enter the number of years: ");
  scanf("%d", &num_years);

  printf("\nYears  ");
  for (i = 0; i < NUM_RATES; i++) { // prints the 5 different intrest rates at the top row
    printf("%11d%%", low_rate + i);
    value[i] = INITIAL_BALANCE;
  }
  printf("\n");

  for (year = 1; year <= num_years; year++) { 
    printf("%3d    ", year);
    for (i = 0; i < NUM_RATES; i++) { 
      rate = (double) ((low_rate + i ) / 12.0 / 100.0 + 1.0); // calculates monthly inrest which will be used to calculate new ammount

      for (int j = 0; j < M; j++) {
        value[i] *= rate;
      }
      printf("%12.2f", value[i]);
    }
    printf("\n");
  }

  return 0;
}

