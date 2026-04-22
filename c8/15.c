/*
 * uses Ceasar cipher to encrypt message. shifts letters according to user specification.
 */

#include <stdio.h>

#define N 80

int main(void)
{
  int shift, i;
  char mess[N] = {'0'}, c;

  printf("Enter message to be encrypted: ");
  for (i = 0; i < N; i++) { //store each char in mess[]
    c = getchar();
    if (c == '\n') break; //signifies end of sentence. if not here we would be stuck in a loop

    mess[i] = c;
  }

  printf("Enter shift ammount (1 - 25): ");
  scanf("%d",  &shift); //ask for shift

  if (shift < 0 || shift > 25) {
    printf("%d is out of bounds. Pick number between 1 - 25\n", shift); //make sure shift is in the boundary
    return 1;
  }

  printf("Encrypted message: ");
  for (int j = 0; j < i; j++) {
    c = mess[j];
    if (mess[j] >= 'A' && mess[j] <= 'Z') {
      printf("%c", ((c - 'A') + shift) % 26 + 'A'); //wrap around formluar
    }
    else if (mess[j] >= 'a' && mess[j] <= 'z') { // handles lowercase letters
      printf("%c", ((c - 'a') + shift) % 26 + 'a');
    }
    else 
      putchar(c); // prints all other characters exactly as they are
  }
  putchar('\n');

  return 0;
}
