//sums up command line arguments which are assumed to be integers

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  (void)argc;
  char **p;
  int sum = 0;

  for (p = &argv[1]; *p != NULL; p++)
    sum += atoi(*p);// atoi(ASCII to int) is a function used to convert a string of characters into an int. eg if str[] = "245", num = atoi(str), now num is 245. it recognizes optional leading signs (- and +). skips all leading spaces and processes all digits until it hits a non numeric character.

  printf("Total: %d\n", sum);

  return 0;
}
