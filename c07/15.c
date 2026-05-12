/*
computes factorial of a positive number
*/

#include <stdio.h>

int main(void)
{
  
  short ff;
  int i, x, factorial, num;
  long fa;
  long long fac;
  float fact;
  double facto;
  long double factor;



  printf("\nSelect a digit to represent how to display factorial as:\n 1 = short  2 = int  3 = long  4 = long long  5 = float  6 = double  7 = long double\nEnter number: ");
  scanf(" %d", &num); //num represents data type user is about to enter. the while loop below ensures they choose from the options given.

  while (num < 1 || num > 7){
    printf("\nERROR: Select a digit from the options below:\n 1 = short  2 = integer  3 = long  4 = long long  5 = float 6 = double  7 = long double\nEnter number: ");
    scanf(" %d", &num);
  }

  printf("Enter a positive number: ");
  scanf(" %d", &x);

  switch (num) {
    case 1:
      ff = 1;
      for (i = 1; i <= x; i++) {
       ff *= i;
      }
      printf("Factorial of %d as a short: %hd\n", x, ff);
      break;
    case 2:
      factorial = 1;
      for (i = 1; i <= x; i++) {
       factorial *= i;
      }
      printf("Factorial of %d as an integer: %d\n", x, factorial);
      break;
    case 3:
      fa = 1;
      for (i = 1; i <= x; i++) {
       fa *= i;
      }
      printf("Factorial of %d as a long: %ld\n", x, fa);
      break;
    case 4:
      fac = 1;
      for (i = 1; i <= x; i++) {
       fac *= i;
      }
      printf("Factorial of %d as a long long: %lld\n", x, fac);
      break;
    case 5:
      fact = 1.0f;
      for (i = 1; i <= x; i++) {
       fact *= i;
      }
      printf("Factorial of %d as a float: %g\n", x, fact);
      break;
    case 6:
      facto = 1.0;
      for (i = 1; i <= x; i++) {
       facto *= i;
      }
      printf("Factorial of %d as a double: %g\n", x, facto);
      break;
    case 7:
      factor = 1.0L;
      for (i = 1; i <= x; i++) {
       factor *= i;
      }
      printf("Factorial of %d as a long double: %Lg\n", x, factor);
      break;
  }

  return 0;
}
