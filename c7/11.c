/*
take first and last name as input
1.display the lastname; a comma and space; first name initial; and a period
2.capitalize the first letter in lastname and the initial of the first name
3.user may input  spaces before first name, between first and last name & after last name
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  //only " %c" in scanf can skip white space, as far as what we have covered

  char f, L, c;

  printf("Enter a first and last name: ");

  scanf(" %c", &f); //skips any space before first name and stores first name initial in f

  while (getchar() != ' '); //skipa the rest of the last name upto spaces.

  scanf(" %c", &L); //skips spaces after first name and store Last name inital in L

  f = toupper(f); L = toupper(L); // capitalizes first and last name initals

  printf("%c", L); //prits lastname capitized initial

  while ((c = getchar()) != ' ' && c != '\n') // terminates at the end of last name
    putchar(c); //prints the rest of the last name.

  printf(", %c.\n", f); //prints a comma then a space then first name initial 

  return 0;
}
