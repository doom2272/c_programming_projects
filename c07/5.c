/*
program computes the value of a word enterd by user, i.e, SCRABBLE.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char c;
  int face_value = 0;

  printf("Enter a word: ");

  while ((c = getchar()) != '\n') {

    switch (toupper(c)) {
      
      case 'D': case 'G': 
        face_value += 2; break;

      case 'B': case 'C': case 'M': case 'P':
        face_value += 3; break;

      case 'F': case 'H': case 'V': case 'W': case 'Y':
        face_value += 4; break;

      case 'K':
        face_value += 5; break;
      
      case 'J': case 'X':
        face_value += 8; break;
      
      case 'Q': case 'Z':
        face_value += 10; break;

      default:
        face_value++; break;
    }
  }

  printf("Scrabble value: %d\n", face_value);

  return 0;
}
