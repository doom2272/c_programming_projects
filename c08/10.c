
/*
 * modifies project 8, cap 5 by storing departure times and arrival times in arrays.
*/

#include <stdio.h>

#define N 8

int main(void)
{
  int user_time, h, m, found,
      dep[N] = {480, 583, 679, 767, 840, 945, 1140, 1305},
      arrival[N] = {616, 712, 811, 900, 968, 1075, 1280, 1430};

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &h, &m);

  user_time = h * 60 + m; //converts user input to minutes after midnight

  printf("Closest departure time is ");
  if (user_time <= 172) { // if usertime is before 2.52, its closer to 21:45
    printf("%d:%.2d , arriving at %d:%.2d\n", dep[N - 1] / 60, dep[N - 1] % 60, arrival[N - 1] / 60, arrival[N - 1] % 60);
    return 0;
  }

  found = 0; // flag tracks if a closest departure time is found inside the loop or not.

  for (int i = 0; i < N - 1; i++) {
    if (user_time <= dep[i] + (dep[i + 1] - dep[i]) / 2) { // checks if the usretime is less than midway between 2 departure time, current and next. if it is the current departure time is closest.
      printf("%d:%.2d , arriving at %d:%.2d\n", dep[i] / 60, dep[i] % 60, arrival[i] / 60, arrival[i] % 60);
      found = 1; // sets our flag to 1 to signify we found our closest departure time
      break;
    }
  }

  if (!found) // if flag is still 0, this means the last departure time is automatically the closest one
    printf("%d:%.2d , arriving at %d:%.2d\n", dep[N - 1] / 60, dep[N - 1] % 60, arrival[N - 1] / 60, arrival[N - 1] % 60);

  return 0;
}
