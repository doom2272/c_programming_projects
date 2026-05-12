
/*
 * modifies prject 11, cap7, now stores last name in an array
 take first and last name as input
 1.display the lastname; a comma and space; first name initial; and a period
 2.capitalize the first letter in lastname and the initial of the first name
 3.user may input  spaces before first name, between first and last name & after last name
 */

#include <stdio.h>
#include <ctype.h>

#define N 20

int main(void)
{
  //only " %c" in scanf can skip white space, as far as what we have covered

  int i;
  char f, Last[N] = {0}, L, c;

  printf("Enter a first and last name: ");

  scanf(" %c", &f); //skips any space before first name and stores first name initial in f

  while ((c = getchar()) != ' ' && c != '\n');//skips the rest of the last name upto spaces. the second test checks cases where user only enters first name then enter
  if (c == '\n') return 1; //if there is no second name, terminate the program.


  while ((L = getchar()) == ' '); //skips spaces between first and last name if there are any

  if (L == '\n') return 1; // if there is a \n after spaces following first name, terminate
  Last[0] = L; //this means we have our first letter in the first name, store it as element 0 in Last[]

  for ( i = 1; i < N; i++) { // stores the rest of the last name
    L = getchar();
    if (L == ' ' || L == '\n') break; //this means we hit the end of the last name
    Last[i] = L;
  }

  printf("You entered the name: %c", toupper(Last[0])); // capitalize the first letter in last name
  for (int j = 1; j < i; j++) { //prints the rest of the last name
    putchar(Last[j]);
  }
  putchar(',');

  printf(" %c.\n", toupper(f));

  return 0;

}
