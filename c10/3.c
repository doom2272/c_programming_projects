
/*NOW remove num_in_rank, num_in_suit, card_exists from the original poker.c ...
 *
 * read and classifies a pocker hand.
 *      straight flush - both a staight and a flush
 *      four-of-a-kind - four cards of the same rank
 *      full house - a three-of-a-kind and a pair
 *      flush - five cards with the same suit
 *      straight - five cards with consecutive ranks
 *      three-of-a-kind - three cards of the same rank
 *      two pairs
 *      pair - two cards of the same rank
 *      high - any other hand
 */


/* #include */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* #define */
#define NUM_RANKS 13
#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

/* typedef */

/* external variables */
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs;  //can be 0, 1 or 2

/* function declarations/ prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/*****************************************************************************
 * main: Calls read_cards, analyze_hand, and print_result repeatedly.        *
 *****************************************************************************/

int main(void)
{

  while (1) {
    read_cards();
    analyze_hand();
    print_result();
  }

  return 0;
}

/* function declarations */

/*****************************************************************************
 * read_cards: Reads the cards into external variables; checks for bad cards *
 *                       and duplicate cards.                                *
 *****************************************************************************/
void read_cards(void)
{

  char c, rank_c, suit_c;
  bool bad_card;
  int cards_read = 0, rank, suit;

  while (cards_read < NUM_CARDS) {
    bad_card = false;

    printf("Enter a card: "); 
    rank_c = getchar();
    switch (rank_c) {    
      case '0':          exit(EXIT_SUCCESS); 
      case '2':          rank = 0; break;
      case '3':          rank = 1; break;
      case '4':          rank = 2; break;
      case '5':          rank = 3; break;
      case '6':          rank = 4; break;
      case '7':          rank = 5; break;
      case '8':          rank = 6; break;
      case '9':          rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default: bad_card = true; 
    }

    suit_c = getchar();
    switch (suit_c) {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default: bad_card = true;
    }


    bool duplicate = false;

    for (int i = 0; i < cards_read; i++) {
      if (hand[i][RANK] == rank && hand[i][SUIT] == suit) {
        duplicate = true;
        break;
      }
    }


    while ((c = getchar()) != '\n')
      if (c != ' ') bad_card = true;

    if (bad_card)
      printf("Bad card; ignored.\n");
    else if (duplicate)
      printf("Duplicate card; ignored.\n");
    else {
      hand[cards_read][RANK] = rank;
      hand[cards_read][SUIT] = suit;
      cards_read++;
    }
  } 
}


/*****************************************************************************
 * analyze_hand: Determine whether the hand contains a straight, flush,      *
 *                       four-of-a-kind, and/or three-of-a-kind; determines  *
 *                       the number of pairs; stores the results into        *
 *                       external variables.                                 *
 *****************************************************************************/
void analyze_hand(void)
{
  int rank, suit, pass, card, run;

  straight = false;
  flush = true;
  four = false;
  three = false;
  pairs = 0;

  //sort the hand by ranks
  for (pass = 1; pass < NUM_CARDS; pass++) {
    for (card = 0; card < NUM_CARDS - pass; card++) {
      int r = hand[card][RANK];
      int s = hand[card][SUIT];

      if (hand[card + 1][RANK] < r) {
        hand[card][RANK] = hand[card + 1][RANK];
        hand[card][SUIT] = hand[card + 1][SUIT];
        hand[card + 1][RANK] = r;
        hand[card + 1][SUIT] = s;
      }
    }
  }

  //check for flush
  suit = hand[RANK][SUIT];

  for (rank = 1; rank < NUM_CARDS; rank++) {
    if (hand[rank][SUIT] != suit) {
      flush = false;
      break;
    }

  }


  // check for straight
  bool skip_straight = false;

  if (hand[RANK][RANK] > 8)
    skip_straight = true;
  else {
    straight = true;

    for (card = 0; card < NUM_CARDS - 1 && !skip_straight; card++) {
      if (hand[card][RANK] + 1 != hand[card + 1][RANK])
        straight = false;
    }
  }


  // check for four-of-a-kind, three-of-a-kind and pairs
  card = 0;

  while (card < NUM_CARDS) {
    rank = hand[card][RANK];
    run = 0;
    do {
      run++;
      card++;
    } while (card < NUM_CARDS && hand[card][RANK] == rank);

    switch (run) {
      case 2: pairs++; break;
      case 3: three = true; break;
      case 4: four = true; break;
    }
  }
}



/*****************************************************************************
 * print_result: Prints the classification of the hand, bassed on the values *
 *                       of the external variables straight, flush, four,    *
 *                       three and pairs.                                    *
 *****************************************************************************/
void print_result(void)
{
  if (straight && flush)        printf("Straight flush");
  else if (four)                printf("Four of a kind");
  else if (three && pairs == 1) printf("Full house");
  else if (flush)               printf("Flush");
  else if (straight)            printf("Straight");
  else if (three)               printf("Three of a kind");
  else if (pairs == 2)          printf("Two pairs");
  else if (pairs == 1)           printf("Pair");
  else                          printf("High card");

  printf("\n\n");
}

