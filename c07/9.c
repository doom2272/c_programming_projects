/*
asks user for 12 hour time and displays 24 hour time.
accepts the following formats;
1:15P, 1:15PM, 1:15p, 1:15pm, 1:15 p, 1:15 PM, 1:15 p, 1:15 pm.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int h, m, h_input;
  char c;

  printf("Enter a 12-hour time: ");
  scanf("%d: %d %c", &h_input, &m, &c);

  c = tolower(c);

  if (h_input == 12 && c == 'a')
    h = 0;
  else if (h_input < 12 && c == 'p')
      h = h_input + 12;
  else 
    h = h_input;

  printf("Equivalent 24-hour time: %.2d:%.2d\n", h, m);

  return 0;
}
