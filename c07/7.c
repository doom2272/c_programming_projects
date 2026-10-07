/*
modify project 6 in cap 3 so that the user can now add, minus divide or multiply 2 fractions.
this depends on the sign they input in between the fraction.
*/

#include <stdio.h>

int main(void)
{

  int num1, num2, den1, den2, num_f, den_f, n_temp, d_temp, r;
  char c;

  printf("Enter two fraction separated by the (+ - * /) sign: ");
  scanf("%d/%d%c%d/%d", &num1, &den1, &c, &num2, &den2);

  
  switch (c) {
    case '+':
    num_f = num1 * den2 + num2 * den1;
    den_f = den1 * den2; break;

    case '-':
    num_f = num1 * den2 - num2 * den1;
    den_f = den1 * den2; break;

    case '*':
    num_f = num1 * num2;
    den_f = den1 * den2; break;

    case '/':
    num_f = num1 * den2;
    den_f = num2 * den1; break;

    default: printf("ERROR: Use the correct operator (+ - * /) between the fractions\n");
  }

  n_temp = num_f;
  d_temp = den_f;

  while (d_temp != 0) { // this while loop is used to get the GCD of fraction.
    r = n_temp % d_temp;
    n_temp = d_temp;
    d_temp = r;
  }

  if (num_f % den_f == 0) // case where anser is a whole number
    printf("Result: %d\n", num_f / den_f);
  else if (num_f > den_f) // case where numerator is larger than denominator
      printf("Result: %d %d/%d\n", num_f / den_f, (num_f % den_f) / n_temp, den_f / n_temp );
  else // fractions where denominator is larger than numerator
    printf("Result: %d/%d\n", num_f / n_temp, den_f / n_temp);
 
  return 0;
}
