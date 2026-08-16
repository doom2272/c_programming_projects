
// Prints a one-month reminder list
/* improves the program by:
 * printing an error and ignore the reminder when the day is -ve or larger than 31,
 * allow user to enter a day, 24-hr time and a reminder, remiders should be sorted by day then time.
 * print a one-year reminder list, require user to enter days in the form month/day.
 */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50  //max number of reminders
#define MSG_LEN 60     // max length of reminder message

int read_line(char str[], int n);

int main(void)
{
  char reminders[MAX_REMIND][MSG_LEN+12];
  char day_str[12], msg_str[MSG_LEN+1];
  int month, day, hr, min, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter month/day 24hr time and reminder: ");
    scanf("%2d/%2d", &month, &day); //expects month/day as format
    if (month == 0 || day == 0)
      break;
    else if (day < 0 || day > 31 || month < 1 || month > 12) { //if day is out of range print error message & ignore it
      while (getchar() != '\n')
        ;
      printf("-- Invalid month or day range! --\n");
      continue;
    }
    scanf("%2d:%2d", &hr, &min); //expects 24 hour time
    sprintf(day_str, "%02d/%02d %02d:%02d", month, day, hr, min); //the zero is used to padd the numbers eg "2/5" is stored as "02/05"
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], day_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;

  str[i] = '\0';
  return i;
}


