/*
prompts phone number then displays in another form
*/

#include <stdio.h>

int main(void)
{
  int f, m, e;

  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%d)%d-%d", &f, &m, &e);

  printf("You entered %d.%d.%d\n", f, m, e);

  return 0;
}
