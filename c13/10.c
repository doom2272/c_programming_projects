/*
take first and last name as input
1.display the lastname; a comma and space; first name initial; and a period
2.capitalize the first letter in lastname and the initial of the first name
3.user may input  spaces before first name, between first and last name & after last name
*/

#include <ctype.h>
#include <stdio.h>

#define NAME_LEN 100

int read_line(char *s, int n);
void reverse_name(char *name);

int main(void)
{
  //only " %c" in scanf can skip white space, as far as what we have covered

  char name[NAME_LEN];

  printf("Enter a first and last name: ");
  read_line(name, NAME_LEN);

  reverse_name(name);

  printf("%s\n", name);

  return 0;
}

int read_line(char *s, int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n - 1)
      s[i++] = ch;
  s[i] = '\0';

  return i;
}

void reverse_name(char *name)
{
  char first_n[30], last_n[30];

  sscanf(name, "%s %s", first_n, last_n);//scanf only reads input from stdin, to use scanf on a variable, use sscanf

  last_n[0] = toupper(last_n[0]);
  first_n[0] = toupper(first_n[0]);
  

  sprintf(name, "%s, %c.", last_n, first_n[0]);//saves the name in the form we want
}
