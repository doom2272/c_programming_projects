//modifies project 9 in chapter 5.
//stores user date inputs in a structure called date.

#include <stdio.h>

struct date {
  int month;
  int day;
  int year;
};

int compare_dates(struct date d1, struct date d2); // returns -1 if d1 is earlier than d2, 1 if d1 is later and 0 if d1 and d2 are the same

int main(void)
{

  struct date d1, d2;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

  int result = compare_dates(d1, d2);

  if (result < 0)
    printf("%d/%d/%d is earlier than %d/%d/%d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
  else if (result > 0)
    printf("%d/%d/%d is earlier than %d/%d/%d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
  else 
    printf("The dates are the same\n");

  return 0;
}


/*****************************************************************************
 * compare_dates: compares 2 date structures. Returns -1 if date1 is earlier *
 *                       than date2, return 1 if date1 is later than date2.  *
 *                       Returns 0 if the dates are the same.                *
 *****************************************************************************/
int compare_dates(struct date d1, struct date d2)
{
  if (d1.year != d2.year)
    return (d1.year < d2.year) ? -1 : 1;
  else if (d1.month != d2.month)
    return (d1.month < d2.month) ? -1 : 1;
  else if (d1.day != d2.day)
    return (d1.day < d2.day) ? -1 : 1;

  return 0;
}
