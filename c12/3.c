//modifies 1b.c. uses array name as a pointer
#include <stdio.h>
#define N 100

int main(void)
{
  char sentence[N], *p = sentence;
  int c;

  printf("Enter a message: ");
  for (; p < sentence + N && (c = getchar()) != '\n'; p++) {
    *p = (char)c;
  }

  printf("Reversal is: ");
  for (--p; p >= sentence; p--) {
    putchar(*p);
  }

  putchar('\n');

  return 0;
}
