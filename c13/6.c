
/* checks planet name 
 * improves program by having it ignore case when comparing command line arguments with strings in planets array.
 */

#include <ctype.h>
#include <stdio.h>

#define NUM_PLANETS 9

int string_equal(const char *s, const char *t);

int main(int argc, char *argv[])
{
  char *planets[] = {"Mercury", "Venus", "Earth", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
  
  int i, j;

  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++)
      if (string_equal(argv[i], planets[j])) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }

  return 0;
}

int string_equal(const char *s, const char *t)// this function compares each character in a string against another string. converts both chars to uppercase before the comparison. returns 1 if all the characters match and the null character in the first string is hit. if strings don't match, it returns 0.
{
  int i;

  for (i = 0; toupper(s[i]) == toupper(t[i]); i++)
    if (s[i] == '\0')
      return 1;

  return 0;
}

