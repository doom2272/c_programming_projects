/*
breaks down ISBN number into different groups
*/

#include <stdio.h>

int main(void)
{
  int g, i, p, n, d;

  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d-%d", &g, &i, &p, &n, &d);

  printf("\nGS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n", g, i, p, n, d);

  return 0;
}
