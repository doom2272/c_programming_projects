
// asks user to guess a number. now there is no global variable. secret_number is moved inside main.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100


void initialize_number_generator(void);
int new_secret_number(void);
void read_guesses(int secret_number);

int main(void)
{
  int secret_number;
  char command;

  printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);

  initialize_number_generator();

  do {
    secret_number = new_secret_number();

    printf("A number has been choosen.\n");
    read_guesses(secret_number);

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
 * returns a randomly select a number between 1 and MAX_NUMBER.
 */
int new_secret_number(void)
{
  return rand() % MAX_NUMBER + 1;
}

/*
 * repeatedly reads user guess and tells user whether guess is too low, too high, or correct.
 * when guess is correct, prints the total number of guesses and returns.
 */
void read_guesses(int secret_number)
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
