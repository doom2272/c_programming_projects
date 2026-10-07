
/*
 * modifies this project by adding find_closest_flight function
 *
ask user to enter 24-hour time, then displays the departure and arrival times for a flight whose departure time is closest to user input
*/

#include <stdio.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
  int user_time, h, m, h_d, m_d, h_a, m_a, departure, arrival; //h_d is hours part in departure time, m_d is minutes. h_a and m_a are for arrival time.
                                                               //departure and arrival store the minutes since midnight from the function find_closest_flight.
  char c_d, c_a;

  printf("Enter a 24-hour time: ");
  scanf("%d :%d", &h, &m);

  user_time = h * 60 + m; //converts user input to minutes after midnight

  find_closest_flight(user_time, &departure, &arrival);


  //the following statements, check to see whether the time is past midday. if so the the time is pm that why our char variables get the 'p'. the time is also converted to 12 hr system  by first dividing the time by 60 (to change the time from minutes from the function to 24 hr system), then 12 is subtracted (to convert 24hr system to 12 hr system)

  if (departure < 720 && arrival < 720)
  {
    c_d = 'a';
    c_a = 'a';

    h_d = departure / 60;
    m_d = departure % 60;

    h_a = arrival / 60;
    m_a = arrival % 60;
  }
  else if (departure < 720 && arrival > 720)
  {
    c_d = 'a';
    c_a = 'p';

    h_d = departure / 60;
    m_d = departure % 60;

    h_a = (arrival / 60) - 12;
    m_a = arrival % 60;
  }
  else 
  {
    c_d = 'p';
    c_a = 'p';

    h_d = departure / 60; //calculate 24 hr first

    // the if below handles the special case where the time is past noon but not yet 13:00 hrs. here we can't subtract 12 from the hours to convert 24 hr to 12 hr system. eg if our time is 767 minutes after midnight, if we convert to 24 hr its 767 / 60 = 12 . if we subtract 12 to convert to 12 hr system we get 12 - 12 = 0. that wrong.

    if (h_d > 12)
      h_d -= 12;
    
    m_d = departure % 60;

    h_a = (arrival / 60) - 12;
    m_a = arrival % 60;
  }

  printf("Closest departure time is %.2d:%.2d %c.m., arriving at %.2d:%.2d %c.m.\n", h_d, m_d, c_d, h_a, m_a, c_a);

  return 0;
}


/*****************************************************************************
 * find_closest_flight: finds the closest departure time to desired_time and *
 *                       stores stores the departure time in *departure_time *
 *                       and the arrival time in *arrival_time               *
 *****************************************************************************/
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{

//all this d's convert the departure times to 24hr system and then to minutes after midnight and the a's do the same for the arrival times.
  int 
    d1 = 480, a1  = 616,
    d2 = 583, a2  = 712,
    d3 = 679, a3  = 811,
    d4 = 767, a4  = 900,
    d5 = 840, a5  = 968,
    d6 = 945, a6  = 1075,
    d7 = 1140, a7 = 1280,
    d8 = 1305, a8 = 1438;

  if (desired_time <= d1 + (d2 - d1) / 2)
  {
    *departure_time = d1;
    *arrival_time = a1;
  }
  else if (desired_time < d2 + (d3 - d2) / 2)
  {
    *departure_time = d2;
    *arrival_time = a2;
  }
  else if (desired_time < d3 + (d4 - d3) / 2)
  {
    *departure_time = d3;
    *arrival_time = a3;
  }
  else if (desired_time < d4 + (d5 - d4) / 2)
  {
    *departure_time = d4;
    *arrival_time = a4;
  }
  else if (desired_time < d5 + (d6 - d5) / 2)
  {
    *departure_time = d5;
    *arrival_time = a5;
  } 
  else if (desired_time < d6 + (d7 - d6) / 2)
  {
    *departure_time = d6;
    *arrival_time = a6;
  }
  else if (desired_time < d7 + (d8 - d7) / 2)
  {
    *departure_time = d7;
    *arrival_time = a7;
  }
  else 
  {
    *departure_time = d8;
    *arrival_time = a8;
  }
}
