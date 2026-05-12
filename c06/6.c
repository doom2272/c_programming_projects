// prompts user to enter n, then prints all the even squares between 1 and n..

#include <stdio.h>

int main(void)
{
  int n, i;

  printf("** prints all the even squares between 1 and user input **\n");

  printf("Enter a number (n): ");
  scanf("%d", &n);

  for (i = 2; i * i <= n; i += 2) {
      printf("%d\n", i * i);
  }
}
