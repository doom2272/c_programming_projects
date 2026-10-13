//prints a one-month reminder list (dynamic string version)
//now uses a structure with a flexible array member.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   // max number of reminders
#define MSG_LEN 60      //max length of reminder message

int read_line(char str[], int n);

int main(void)
{
  struct vstring {
    int len;
    char chars[]; //flexible array member.
  };
  struct vstring *reminders[MAX_REMIND];
  char day_str[3], msg_str[MSG_LEN+1];
  int day, i, j, num_remind = 0, message_len, total_reminder_len;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    sprintf(day_str, "%2d", day);
    message_len = read_line(msg_str, MSG_LEN);

    total_reminder_len = strlen(day_str) + message_len;

    for (i = 0; i < num_remind; i++)
      if (strncmp(day_str, reminders[i]->chars, 2) < 0)
        break;
    for (j = num_remind; j > i; j--)
      reminders[j] = reminders[j-1];

    reminders[i] = malloc(sizeof(struct vstring) + (total_reminder_len + 1));
    if (reminders[i] == NULL) {
      printf("-- No space left --\n");
      break;
    }

    reminders[i]->len = total_reminder_len;

    strcat(strcpy(reminders[i]->chars, day_str), msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]->chars);

  i = 0;
  while (i < num_remind) {
  free(reminders[i++]);
  }

  putchar('\n');

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

