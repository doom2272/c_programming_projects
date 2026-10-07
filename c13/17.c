
// modifies original project by adding the is_palindrome function

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 100

bool is_palindrome(const char *message);

int main(void)
{
  char message[N+1], *p;
  int c;

  printf("Enter a message: ");
  for (p = message; p < message + N && (c = getchar()) != '\n';){
    if (isalpha((unsigned char)c)) {
      *p++ = (char)tolower((unsigned char)c); //only advance our pointer if we encounter a letter to store in our array.
    }
  }
  *p = '\0';

  if (is_palindrome(message))
    printf("Palindrome\n");
  else 
    printf("Not a palindrome\n");

  return 0;
}

bool is_palindrome(const char *message)
{
  const char *p = message;
  const char *q = message;

  while (*q) //make q point to the last character in message which is the null character
    q++;

  if (q == message) //catches empty input, when a user enters 'ENTER' as the input
    return false;

  q--; //q now points at a character not the null character

  while (p < q) {
    if (*p != *q)
      return false;
    p++;
    q--;
  }

  return true;
}
