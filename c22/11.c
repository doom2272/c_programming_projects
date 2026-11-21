// reads date and outputs; month in a word, day, year
// date could have the form mm/dd/yyyy or mm-dd-yyyy

#include <stdio.h>
#include <stdlib.h>

void valid_day_month(short unsigned month, short unsigned day);

int main(void) {
  char date[20];
  char *months[] = {" ",       "January",  "February", "March",  "April",
                    "May",     "June",     "July",     "August", "September",
                    "October", "November", "December"};
  short unsigned month = 0, day = 0;
  int year = 0;

  printf("Enter date: mm dd yyyy: ");
  if (fgets(date, sizeof(date), stdin) == NULL) {
    if (ferror(stdin))
      perror("\nfgets");
    else if (feof(stdin))
      fprintf(stderr, "\nNo input entered\n");

    return 1;
  }

  if ((sscanf(date, "%hu /%hu /%d", &month, &day, &year)) == 3) {
    valid_day_month(month, day);
    printf("%s %hu, %d\n", months[month], day, year);
    return 0;
  } else if ((sscanf(date, "%hu -%hu -%d", &month, &day, &year)) == 3) {
    valid_day_month(month, day);
    printf("%s %hu, %d\n", months[month], day, year);
    return 0;
  } else
    printf("Only enter the date in the form mm/dd/yyyy or mm-dd-yyyy\n");
  return 1;
}
void valid_day_month(short unsigned month, short unsigned day) {

  if (month <= 0 || month > 12) {
    fprintf(stderr, "Invalid month: %hu\n", month);
    exit(EXIT_FAILURE);
  }
  if (day <= 0 || day > 31) {
    fprintf(stderr, "Invalid day: %hu\n", day);
    exit(EXIT_FAILURE);
  }
}
