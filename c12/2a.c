#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define N 100

int main(void)
{
  char message[N], c;
  int i, end = 0;
  bool is_palindrom = true;

  printf("Enter a message: ");
  for (i = 0; i < N && ((c = getchar()) != '\n'); i++) {
    if (isalpha(c)) { //only populate array if char is a letter
      message[end] = tolower(c); //tolower other wise A and a would be intepreted as different letters. also we use end because i increments when every char is read. we only want to move through the array when we get a letter.
      end++;//tells us the end of our array (which contains only letter)
      }
  }


  for (int j = 0,  k = end - 1; j < k; j++, k--) { //one int starts at the start of our array and the other at the end
    if (message[j] != message[k]) { //if letter don't match, its not a palindrome, set the bool is_palindrome to false and exit immediately.
      is_palindrom = false;
      break;
    }
  }

  if (is_palindrom)
    printf("Palindrome\n");
  else 
    printf("Not a palindrome\n");

  return 0;
  
}
