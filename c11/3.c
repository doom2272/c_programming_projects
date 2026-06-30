// modifies the project by adding function reduce.
// program asks user for a fraction then reduces it to its lowest terms.

#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
  int num, den, r_num, r_den;

  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &den);

  reduce(num, den, &r_num, &r_den);
  
  printf("In lowest terms: %d/%d\n", r_num, r_den);

  return 0;
}


/*****************************************************************************
 * reduce: reduces a fraction to its lowest term. stores the reduced         *
 *                       numerator at the variable reduced_numerator points  *
 *                       at. same for denominator.                           *
 *****************************************************************************/
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
  int m = numerator, n = denominator, r;

  while (n != 0) {
    r = m % n;
    m = n;
    n = r;
  }
  
  *reduced_numerator = numerator / m;

  *reduced_denominator = denominator / m;

}
