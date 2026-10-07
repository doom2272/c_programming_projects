/*
uses newton's method to calculate square root of a number (positive floating-point number)
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
  double x, y = 1.0, div, average, old_y; //x is the user input, y is an initial guess which = 1.0.  div = x/y and average = (y + x/y)/2, old_y is the previous value of y

  printf("Enter a positive number: ");
  scanf("%lf", &x);

  while (x < 0) { //this while loop ensure user enters a positive number
    printf("ERROR: Enter a positive number: ");
    scanf("%lf", &x);
  }

  do {
    old_y = y;
    div = x / y;
    average = (y + div) / 2;
    y = average;
  } while (fabs(old_y - y) > (.00001 * y)); //fabs(), floating-points absolute value can be thought as a way to strip the negative sign. We only care about the distance between 2 values. eg if result is 0.05 (fabs return 0.05), if its -0.05 (fabs still returns 0.05)

  printf("Square root: %g\n", y);

  return 0;
}
