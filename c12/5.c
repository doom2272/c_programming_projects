/*
 * modifies project 14, cap 8 to use pointers.
 * reverses words in a sentence. stores each character in an array. stops storing characters at . ? !
 */

#include <stdio.h>

#define N 50

int main(void)
{
  char *end, *start;
  char sentence[N] = {0}, stop = '.', c, *p;

  printf("Enter a sentence: ");

  for (p = sentence; p < sentence + N; p++) { 
    c = getchar();

    if (c == '.' || c == '?' || c == '!' || c == '\n') { 
      if (c != '\n')
        stop = c;
      break;
    }

    *p = c; 
  }

  for ( --p; p >= sentence; p--) { 
    while (p >= sentence && *p == ' ') p--; 

    if (p < sentence) break; 

    end = p; 

    while (p >= sentence && *p != ' ') 
      p--;

    start = p + 1; 

    for ( char *t = start; t <= end; t++) 
      putchar(*t);

    if (start > sentence) putchar(' '); 

    p = start;

  }
  putchar(stop); 

  putchar('\n');

  return 0;
}
