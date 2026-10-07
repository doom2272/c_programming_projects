/*
 * sorts a 1D array.
 */

#include <stdio.h>
#include "quicksort.h"

#define N 10


int main(void)
{
  int a[N], i = 0, ch;


  printf("Enter upto %d numbers to be sorted: ", N);
  do {

    if (scanf("%d", &a[i]) == 1) { 
      i++;
    }

    while ((ch = getchar()) == ' '); 

  }while (ch != '\n' && i < N); 

  quicksort(a, 0, i - 1); 

  printf("In sorted order: ");
  for (int j = 0; j < i; j++)
    printf("%d ", a[j]); 

  printf("\n");

  return 0;
}

