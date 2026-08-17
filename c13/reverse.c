/*
 * program that prints its arguments in reverse.
 * eg "4c void and null" outputs "null and void"
 */

#include <stdio.h>

int main(int argc, char **argv)
{
  char **p;

  printf("\n");

  for (p = &argv[argc-1]; *p >= argv[1]; p--)
    printf("%s ", *p);

  printf("\n\n");

  return 0;
}
