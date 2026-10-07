/*
 * converts user input which might cointain character into numbers. store user input in an array.
 */

#include <stdio.h>
#include <ctype.h>

#define N 15

int main(void)
{
  int i;
  char c, num[N] = {0}, converted[N] = {0};

  printf("Enter phone number: ");
  for ( i = 0; i < N; i++){
    scanf("%c", &c);
    if (c == '\n') break; // exit loop if newline character is read

    num[i] = toupper(c);

    switch (num[i]) { //when using char type in switch, always put the characters in ''. translates te letters from user input to numbers and stores it an array 
      case 'A': case 'B': case 'C': converted[i] = '2'; break;
      case 'D': case 'E': case 'F': converted[i] = '3'; break;
      case 'G': case 'H': case 'I': converted[i] = '4'; break;
      case 'J': case 'K': case 'L': converted[i] = '5'; break;
      case 'M': case 'N': case 'O': converted[i] = '6'; break;
      case 'P': case 'R': case 'S': converted[i] = '7'; break;
      case 'T': case 'U': case 'V': converted[i] = '8'; break;
      case 'W': case 'X': case 'Y': converted[i] = '9'; break;
      default: converted[i] = num[i]; break; // if its not a letter stores it as is
    }
  }

  if (i == N) { // handles cases where user inputs more than 15 characters. this is used to clear the buffer of the excess characters
  while (getchar() != '\n');
  }

  printf("In numeric form: ");
  for (int j = 0; j < i; j++){ // only prints as many digits as was read in user input. if user enters less than 15 characters, it doesn't print 0's. thats why i used j < i
    putchar(converted[j]);
  }

  putchar('\n');

  return 0;
}
