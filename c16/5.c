//modifies project 8 in chapter 5.
//adds the different departure and arrival times in an array of structures.
//each element in the array stores the departure time and arrival time as minutes after midnight


#include <stdio.h>

#define N 8 // all filghts

struct time {
  int dep;
  int arr;
};

void print_flight_info(struct time f);

int main(void)
{
  struct time flights[N] = {
    {480, 616},
    {583, 712},
    {679, 817},
    {767, 900},
    {840, 968},
    {945, 1075},
    {1140, 1280},
    {1305, 1438}
  };

  int user_dep, hr, min;

  printf("Enter departure time in 24 hour format (hh:mm): ");
  scanf("%d :%d", &hr, &min);

  user_dep = hr * 60 + min;

  printf("Closest departure time is ");
  for (int i = 0; i < N - 1; i++)
    if (user_dep <= flights[i].dep + (flights[i+1].dep - flights[i].dep) / 2) {
      print_flight_info(flights[i]);
      return 0;
    }

  print_flight_info(flights[N-1]);
  return 0;

}



/*****************************************************************************
 * print_flight_info: Calculates hours and minutes from f.dep and f.arr.     *
 *                       Adjusts hours for midnight and 12 hour clock.       *
 *                       Determine a.m, p.m or noon string. print a single   *
 *                       formatted line.                                     *
 *****************************************************************************/
void print_flight_info(struct time f)
{     
  int dep_hour = f.dep / 60, arr_hour = f.arr / 60; // converts minutes after midnight to 24 hour system and stores both hours at dep_hour and arr_hour
  char *dep_period = f.dep == 720 ? "noon" : (f.dep < 720 ? "a.m" : "p.m"); // determines what the period should be for departure time (am, pm or noon)
  char *arr_period = f.arr == 720 ? "noon" : (f.arr < 720 ? "a.m" : "p.m"); //does the same for arrival time.

  if (dep_hour == 0) //avoids printing 00:45 (after midnight) as 0:45 am. instead changes 0 to 12.
    dep_hour = 12;

  if (arr_hour == 0)
    arr_hour = 12;

  if (dep_hour > 12) //if hours (24 hr system) is larger than 12, minus 12. so 13 becomes 1.
    dep_hour -= 12;

  if (arr_hour > 12)
    arr_hour -= 12;

  printf("%d:%02d %s., arriving at %d:%02d %s.\n", dep_hour, f.dep % 60, dep_period, arr_hour, f.arr % 60, arr_period);
}
