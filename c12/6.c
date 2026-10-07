// sorts an array of integers using quicksort algorithm. use pointers

#include <stdio.h>

#define N 10

void quicksort(int *low, int *high);
int *split(int *low, int *high);

int main(void)
{
  int a[N], *q, *p, *r;

  printf("Enter %d numbers to be sorted: ", N);
  for (q = a; q < a + N; q++)
    scanf("%d", q);

  p = a;

  quicksort(p, q - 1);

  printf("In sorted order: ");
  for (r = a; r < a + N; r++)
    printf("%d ", *r);
  printf("\n");

  return 0;

}

void quicksort(int *low, int *high)
{
  int *middle;

  if (low >= high) return;
  middle = split(low, high);
  quicksort(low, middle - 1);
  quicksort(middle + 1, high);
}

int *split(int *low, int *high)
{
  int part_element = *low;

  for (;;) {
    while (low < high && part_element <= *high)
      high--;
    if (low >= high) break;
    *low++ = *high;

    while (low < high && *low <= part_element)
      low++;
    if (low >= high) break;
    *high-- = *low;
  }

  *high = part_element;
  return high;
}
