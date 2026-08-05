#include <stdio.h>
#define N 100

int main(void)
{
  char sentence[N];
  int end = 0, c;

  printf("Enter a message: ");
  for (int i = 0; i < N && (c = getchar()) != '\n'; i++) {
    sentence[i] = (char)c;
    end = i + 1;
  }

  printf("Reversal is: ");
  for (int i = end - 1; i >= 0; i--) {
    printf("%c", sentence[i]);
  }

  printf("\n");

  return 0;
}
