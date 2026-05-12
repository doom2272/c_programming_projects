/*
 * converst user's message into B1FF.
 */
 
#include <stdio.h>
#include <ctype.h>

#define LEN ((int) (sizeof(message) / sizeof(message[0])))

int main(void)
{
  char message[100], letters;
  int count;

  printf("Enter message: ");

  for (int i = 0; i < LEN; i++) {
    scanf("%c", &letters); //reads each letter individually
    count = i; //track how many letters are in the input
    if (letters == '\n') //stop reading if \n is seen, it means its the end of user input
      break;
    message[i] = toupper(letters); // all read letters are stored in this array after conversion to uppercase
  }

  for (int i = 0; i < count; i++) { // substitutes numbers for certain letters
    switch (message[i]) {
      case 'A':
        message[i] = '4';
        break;
      case 'B':
        message[i] = '8';
        break;
      case 'E':
        message[i] = '3';
        break;
      case 'I':
        message[i] = '1';
        break;
      case 'O':
        message[i] = '0';
        break;
      case 'S':
        message[i] = '5';
        break;

    }
  }

  int j, count2;

  for ( j = count; j < count + 10; j++) { // adds 10 !'s after users input
    if (j >= LEN) // adds exclamation marks only if there is elements in the array after user's input is stored. otherwise we would be going out of boundary.
      break;
    message[j] = '!';
  }
  count2 = j;

  printf("In B1FF-speak: ");
  for (int i = 0; i < count2; i++){
    putchar(message[i]);
  }

  printf("\n");

  return 0;
}
