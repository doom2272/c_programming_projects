#include <stdio.h>

#define N 100

void selection_sort(int n, int a[n]);

int main(void)
{
  int a[N], n = 0;
  char ch;

  printf("Enter a series of integers:");
  while (n < N ) {
    if (scanf("%d", &a[n]) == 1)
      n++; //determines the length of user's array

    ch = getchar(); 
    if (ch == '\n')
      break; //breaks at ENTER
  }

  if (n > 0)
    selection_sort(n, a);

  printf("Sorted form: ");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);

  printf("\n\n");

  return 0;
}

//searches for the largest element and moves it to the last position in the array
//the function then calls itself recursively to do the same to the array, excluding the last element which is correctly sorted
void selection_sort(int n, int a[n])
{
  if (n <= 1)
    return;

  int max_i = 0;

  for (int i = 1; i < n; i++) {
    if (a[i] > a[max_i])
      max_i = i;
  }

  int temp = a[max_i];
  a[max_i] = a[n - 1];
  a[n - 1] = temp;

  selection_sort(n - 1, a);
}
