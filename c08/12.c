/*
 * program computes the value of a word enterd by user, i.e, SCRABBLE. Now the value are stored in a array, unlike previously where a switch statement was used.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int total = 0, success = 1;
  char c, face_value[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // face_value contains the values for each letter. Eg index 0 is letter A which has the value 1

  printf("Enter a word: ");

  while ((c = getchar()) != '\n') {

    c = toupper(c);

    if (c < 'A' || c > 'Z') { // if value of c exceeds this limits, its not a letter, so exit loop
      printf("%c is not a letter!!!!\n", c); // shows which character was not a letter
      success = 0; // changes flag variable to 0
      break;
    }

    total += face_value[c - 'A']; // looks for letter value from array and adds it to total

  }

  if (success) // only prints this if flag variable is 1, if its 0 we ignore this, because we already printed the error message
    printf("Scrabble value: %d\n", total);

  return 0;
}
