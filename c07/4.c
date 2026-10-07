/*program take user alphabet input and converts it to number, like the one on phones with keypads.
it only changes letters, it also assumes all user input entered by user is uppercase.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char c;

  printf("Enter phone number: ");
  do {
    scanf("%c", &c);

    c = toupper(c);

    switch (c) { //when using char type in switch, always put the characters in '' 
      case 'A': case 'B': case 'C': printf("2"); break;
      case 'D': case 'E': case 'F': printf("3"); break;
      case 'G': case 'H': case 'I': printf("4"); break;
      case 'J': case 'K': case 'L': printf("5"); break;
      case 'M': case 'N': case 'O': printf("6"); break;
      case 'P': case 'R': case 'S': printf("7"); break;
      case 'T': case 'U': case 'V': printf("8"); break;
      case 'W': case 'X': case 'Y': printf("9"); break;
      default: putchar(c); break;

    }
  } while (c != '\n');

  return 0;
}
