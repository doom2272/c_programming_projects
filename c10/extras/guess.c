// asks user to guess a number. uses a global variable secret_number, declared outside all functions.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

int secret_number; //global variable.

void initialize_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);

int main(void)
{
  char command;

  printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);

  initialize_number_generator();

  do {
    choose_new_secret_number();

    printf("A number has been choosen.\n");
    read_guesses();

    printf("Play again? (Y/N) ");
    scanf(" %c", &command);
    printf("\n");

  } while (command == 'y' || command == 'Y');

  return 0;
}

/*
 * intialize the random number generator using time of the day.
 */
void initialize_number_generator(void)
{
  srand((unsigned) time(NULL));
}

/*
 * randomly select a number between 1 and MAX_NUMBER and store it in secret_number.
 */
void choose_new_secret_number(void)
{
  secret_number = rand() % MAX_NUMBER + 1;
}

/*
 * repeatedly reads user guess and tells user whether guess is too low, too high, or correct.
 * when guess is correct, prints the total number of guesses and returns.
 */
void read_guesses(void)
{
  int num_guesses = 0, guess;

  while (1) {
    num_guesses++;
    printf("Enter guess: ");
    scanf("%d", &guess);

    if (guess == secret_number) {
      printf("You won in %d guesses!\n\n", num_guesses);
      return;
    }
    else if (guess < secret_number)
      printf("Too low; try again.\n");
    else 
      printf("Too high; try again.\n");
  }
}
