/*
modifies project 8 cap 5 so that user enters 12 hour time followed by PM or AM.
here is a list of valid inputs:
1:15P, 1:15PM, 1:15p, 1:15pm, 1:15 p, 1:15 PM, 1:15 p, 1:15 pm.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char c;
  int user_time, h_temp, h, m,
//all this d's convert the departure times to 24hr system and then to minutes after midnight.
      d1 = 480,
      d2 = 583,
      d3 = 679,
      d4 = 767,
      d5 = 840,
      d6 = 945,
      d7 = 1140,
      d8 = 1305;

  printf("Enter a 12-hour time (hr:min am/pm): ");
  scanf("%d :%d %c", &h_temp, &m, &c);

  c = toupper(c);

  if (h_temp < 12 && c == 'P')// makes sure 12pm is not changed to 24:00
    h = h_temp + 12;
  else if (h_temp == 12 && c == 'A')// makes sure 12AM is 0 in 24 hour time.
      h = 0;
  else 
    h = h_temp;

  user_time = h * 60 + m; //converts user input to minutes after midnight

  printf("Closest departure time is ");

  if (user_time <= d1 + (d2 - d1) / 2 && user_time >= 173)//the 173 is used to wrap around
    printf("8:00 a.m., arriving at 10:16 a.m.\n");
  else if (user_time < d2 + (d3 - d2) / 2)
      printf("9:43 a.m., arriving at 11:52 a.m.\n");
  else if (user_time < d3 + (d4 - d3) / 2)
      printf("11:19 a.m., arriving at 1:31 p.m.\n");
  else if (user_time < d4 + (d5 - d4) / 2)
      printf("12:47 p.m., arriving at 3:00 p.m.\n");
  else if (user_time < d5 + (d6 - d5) / 2)
      printf("2:00 p.m., arriving at 4:08 p.m.\n");
  else if (user_time < d6 + (d7 - d6) / 2)
      printf("3:45 p.m., arriving at 5:55 p.m.\n");
  else if (user_time < d7 + (d8 - d7) / 2)
      printf("7:00 p.m., arriving at 9:20 p.m.\n");
  else 
    printf("9:45 p.m., arriving at 11:58 p.m.\n");

  return 0;
}
