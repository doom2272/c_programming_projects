//use pointer instead of an int as in 1a
#include <stdio.h>
#define N 100

int main(void)
{
  char sentence[N], c, *p = &sentence[0];

  printf("Enter a message: ");
  for (; p < &sentence[N] && (c = getchar()) != '\n'; p++) {
    *p = c;
  }

  printf("Reversal is: ");
  for (--p; p >= &sentence[0]; p--) { //we start at --p because the previous loop moved p just past the last character stored in sentence. so to start at the last element we use --p.
    putchar(*p);
  }

  putchar('\n');

  return 0;
}
