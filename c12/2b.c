// modifies 2a.c by using pointers instead of subscripting

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define N 100

int main(void)
{
  char message[N], *p;
  bool is_palindrome = true;
  int c;

  printf("Enter a message: ");
  for (p = &message[0]; p < &message[N] && ((c = getchar()) != '\n');){
    if (isalpha((unsigned char)c)) {
      *p++ = (char)tolower((unsigned char)c); //only advance our pointer if we encounter a letter to store in our array.
    }
  }

  char *q = &message[0]; // we need this pointer to point at the beginning of our array. since p is already pointing at memory just past the last letter we stored
  for (--p; q < p; q++, p--) { //p is decremented immediately because as noted, it's pointing at the address just past the last letter we stored
    if (*q != *p) {
      is_palindrome = false;
      break;
    }
  }

  if (is_palindrome)
    printf("Palindrome\n");
  else 
    printf("Not a palindrome\n");

  return 0;
}
