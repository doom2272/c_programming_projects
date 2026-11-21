/*
 * modifies project 8, cap 5
 *
 * obtains arrival and departure from a file, which has the times in 24-hour
 * system and are separated by one or more spaces.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TIMES 1000
#define LINE_LEN 50

struct {
  int dep, arr; // stores times as minutes after midnight
} times[MAX_TIMES];

void min_to_12hr(int ind);

int main(void) {

  FILE *fp;

  if ((fp = fopen("flights.dat", "r")) == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  char line[LINE_LEN + 1];
  unsigned short dep_h, dep_m, arr_h, arr_m;
  int flights_read = 0, user_time = 0, h, m;

  while (fgets(line, sizeof(line), fp) != NULL && flights_read < MAX_TIMES) {
    if (sscanf(line, "%hu :%hu %hu :%hu", &dep_h, &dep_m, &arr_h, &arr_m) ==
        4) {
      times[flights_read].dep = dep_h * 60 + dep_m;
      times[flights_read].arr = arr_h * 60 + arr_m;
      flights_read++;
    } else
      fprintf(stderr, "Error reading line %d in flights.dat\n",
              flights_read + 1);
  }

  if (ferror(fp)) {
    perror("fgets");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  if (flights_read == 0) {
    fprintf(stderr, "flights.dat was empty\n");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  printf("Enter a 24-hour time: ");
  scanf("%d :%d", &h, &m);

  user_time = h * 60 + m; // converts user input to minutes after midnight

  int best_ind = 0;
  for (int i = 1; i < flights_read; i++) {
    if (abs(user_time - times[i].dep) < abs(user_time - times[best_ind].dep))
      best_ind = i;
  }

  printf("Closest departure time is ");
  min_to_12hr(best_ind);

  fclose(fp);

  return 0;
}

void min_to_12hr(int ind) {
  unsigned short dep_hr, dep_min, arr_hr, arr_min,
      dep_min_after_mid = times[ind].dep, arr_min_after_mid = times[ind].arr;

  dep_hr = dep_min_after_mid / 60;
  dep_min = dep_min_after_mid % 60;

  arr_hr = arr_min_after_mid / 60;
  arr_min = arr_min_after_mid % 60;

  printf("%hu:%02hu %s, arriving at %hu:%02hu %s\n",
         (dep_hr == 0)    ? 12
         : (dep_hr <= 12) ? dep_hr
                          : dep_hr - 12,
         dep_min,
         (dep_min_after_mid == 720)  ? "noon"
         : (dep_min_after_mid < 720) ? "a.m."
                                     : "p.m.",
         (arr_hr == 0)    ? 12
         : (arr_hr <= 12) ? arr_hr
                          : arr_hr - 12,
         arr_min,
         (arr_min_after_mid == 720)  ? "noon"
         : (arr_min_after_mid < 720) ? "a.m."
                                     : "p.m.");
}
