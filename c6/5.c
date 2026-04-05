// modify previous project so that now a user can enter 3 or more digits and get a reversed version.

#include <stdio.h>

int main(void)
{
  int n;

  printf("** enter a number and get its reversal **\n");

  printf("Enter a number: ");
  scanf("%d", &n);

  printf("The reversal is: ");
  do {
    printf("%d", n % 10);
    n /= 10;
  } while (n != 0);

  printf("\n");
}
