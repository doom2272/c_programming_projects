/*
converts time to 12 hour system
*/

#include <stdio.h>

int main(void)
{
  int h, m;

  printf("Enter a 24-hour time: ");
  scanf("%d :%d", &h, &m);

  if (h < 11)
    printf("Equivalent 12-hour time %d:%d AM\n", h == 0 ? 12 : h, m);
  else 
    printf("Equivalent 12-hour time %d:%d PM\n", h == 12 ? 12 : h - 12, m);

  return 0;
}
