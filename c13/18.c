//accepts date, mm/dd/yyyy from user. it then prints in the form month dd, yyyy.
//eg 2/17/2011 becomes February 17, 2011.
//month names are stored in a array of pointers. the pointer point to strings.

#include <stdio.h>
int main(void)
{
  int month, day, year;
  char *month_names[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  char date_named[20+1];

  printf("Enter a date (mm/dd/yyyy): ");
  scanf(" %2d / %2d / %4d", &month, &day, &year);//spaces between the conversion specificaton for case where user might input spaces between the month, day or year.

  if (month < 1 || month > 12) {
    printf("-- Month must be between 1 and 12! --\n");
    return 1;
  }

  if (day < 1 || day > 31) {
    printf("-- Day must be between 1 and 31! --\n");
    return 1;
  }

  sprintf(date_named, "%s %d, %d", month_names[month], day, year); //save string with the desired output in date_named.

  printf("You entered the date %s\n", date_named);

  return 0;
}
