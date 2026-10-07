
/*
 * deals aa random hand of cards.
 * modified to print full names of cards it deals.
 * rank_code and suit_code are now arrays containing pointer to strings.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false}; //sets all the elements in in_hand to false. used to check if card has been picked before.
  int num_cards, rank, suit;
  const char *rank_code[] = {"Two of ", "Three of ", "Four of ", "Five of ", "Six of ", "Seven of ","Eight of ", "Nine of ",
                            "Ten of ", "Jack of ", "Queen of ", "King of ", "Ace of "};
  const char *suit_code[] = {"clubs", "diamonds", "hearts", "spades"};

  srand((unsigned) time(NULL)); //seed rand, uses the value from time function(which return seconds elapsed since 1st Jan 1970) as a new seed each time(starting point) the rand function is called in this program. since time is always moving forward, the seed will always be different.

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand:\n");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS; //the % operator keeps the random number within the bounds of array. i.e here the limits are 0 and 3.
    rank = rand() % NUM_RANKS;
    if (!in_hand[suit][rank]) { //if the card is not picked before
      in_hand[suit][rank] = true; //chanages its state to true so that it can't be used again.
      num_cards--;
      printf(" %s%s\n", rank_code[rank], suit_code[suit]); //goes to both arrays and uses the index obtained from the 2 rand() functions above to return the respective elements in the char type array of pointers.
    }
  }
  printf("\n");

  return 0;

}
