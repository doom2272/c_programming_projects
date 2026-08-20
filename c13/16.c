
#include <stdio.h>

#define N 100

void reverse(char *message);  

int main(void)
{
  char sentence[N+1];
  int c, i;

  printf("Enter a message: ");
  for (i = 0; i < N && (c = getchar()) != '\n'; i++) {
    sentence[i] = (char)c;
  }
  sentence[i] = '\0';

  reverse(sentence);

  return 0;
}

void reverse(char *message)
{
  char *p = message; 
  char *q = message;

  while (*q) { //make q point to the null character at the end of message.
    q++;
  }

  if (q > message) //if message has any char, decrement q so that it points to a char and not the null character.
    q--;

  while (p < q){
    char temp = *p;
    *p = *q;
    *q = temp;
    p++;
    q--;
  }

  printf("Reversal is: %s\n", message);
}
