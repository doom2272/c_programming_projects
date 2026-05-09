#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 6

int roll_dice(void);
bool play_game(void);

int main(void)
{
  int wins = 0, losses = 0;
  char command;

  srand((unsigned) time(NULL));

  do {

    if (play_game()) {
      wins++;
      printf("You win!\n");
    }
    else {
      losses++;
      printf("You lose!\n");
    }

    printf("\nPlay again? ");
    scanf(" %c", &command);
  } while(tolower(command) == 'y');

  printf("\nWins: %d  Losses: %d\n", wins, losses);

  return 0;
}

int roll_dice(void)
{
  int first, second;

  first = (rand() % N) + 1;
  second = (rand() % N) + 1;

  return first + second;

}

bool play_game(void)
{
  int point, initial_roll = roll_dice(), current_roll;

  printf("\nYou rolled: %d\n", initial_roll);

  if (initial_roll == 7 || initial_roll == 11)
    return true;
  else if (initial_roll == 2 || initial_roll == 3 || initial_roll == 12)
    return false;
  else {
    point = initial_roll;
    printf("Your point is %d\n", point);
  }


  while (true) {
    current_roll = roll_dice();

    printf("You rolled: %d\n", current_roll);

    if (point == current_roll)
      return true;
    else if (current_roll == 7)
      return false;
  }

}
