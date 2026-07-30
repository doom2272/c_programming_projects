//finds the largest and smallest elements in an array. uses pointers.

#include <stdio.h>

#define N 10

void max_min(int *a, int *end, int *max, int *min);

int main(void)
{
  int b[N], *p , big, small;

  printf("Enter %d numbers: ", N);
  for (p = b; p < b + N; p++)
    scanf("%d", p);

  max_min(b, p, &big, &small);

  printf("Largest: %d\n", big);
  printf("Smallest: %d\n", small);

  return 0;
}

void max_min(int *a, int *end, int *max, int *min)
{
  int *q;

  *max = *min = *a;
  for (q = a + 1; q < end; q++) {
    if (*q > *max)
      *max = *q;
    else if (*q < *min)
      *min = *q;
  }
}
