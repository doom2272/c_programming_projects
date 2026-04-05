// prints a one month calender, from starting day of the week, printing dates on a new line if its the last day of the week.

#include <stdio.h>

int main(void)
{

  int i, n, w;

  printf("** prints a one month calender starting with day of the week provided **\n");

  printf("Enter the number of days in month: ");
  scanf("%d", &n);

  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &w);

  printf("\n Su Mo Tu We Th Fr Sa\n");

  for (i = 1; i < w; i++) {
    printf("   ");
  }

  for (i = 1; i <= n; i++) {
    printf("%2d ", i);

    if ((i + w - 1) % 7 == 0) //very important logic used for grid programming!!!
      printf("\n");
  }
}
