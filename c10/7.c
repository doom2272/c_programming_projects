#include <ctype.h>
#include <stdio.h>

#define MAX_DIGITS 10
#define HEIGHT 3
#define WIDTH 40

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};

char digits[HEIGHT][WIDTH];

void clear_digits(void);
void process_digit(int digit, int position);
void print_digits(void);

int main(void)
{
  int position = 0;
  char c;

  clear_digits();

  printf("Enter a number: ");
  while ((c = getchar()) != '\n' && position < MAX_DIGITS) {
    if (isdigit(c)) {
      process_digit(c - '0', position);
      position++;
    }
  }

  print_digits();

  putchar('\n');

  return 0;
}



/*****************************************************************************
 * clear_digits_array: store blank characters into all elements of digits    *
 *                       array.                                              *
 *****************************************************************************/
void clear_digits(void)
{
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      digits[i][j] = ' ';
    }
  }
}


/*****************************************************************************
 * process_digit: store seven-segment representation of digit into a specific*
 *                       position in the digits array (positions range from 0*
 *                       to MAX_DIGITS - 1).                                 *
 *****************************************************************************/
void process_digit(int digit, int position)
{
  int start_col = position * 4;

  if (segments[digit][0] == 1) {digits[0][start_col + 1] = '_';}
  if (segments[digit][1] == 1) {digits[1][start_col + 2] = '|';}
  if (segments[digit][2] == 1) {digits[2][start_col + 2] = '|';}
  if (segments[digit][3] == 1) {digits[2][start_col + 1] = '_';}
  if (segments[digit][4] == 1) {digits[2][start_col + 0] = '|';}
  if (segments[digit][5] == 1) {digits[1][start_col + 0] = '|';}
  if (segments[digit][6] == 1) {digits[1][start_col + 1] = '_';}
}



/*****************************************************************************
 * print_digits_array: display the rows of the digits array, each on a single*
 *                       line;                                               *
 *****************************************************************************/
void print_digits(void)
{

  for (int i = 0; i < HEIGHT; i++){
    for (int j = 0; j < WIDTH; j++) {
      putchar(digits[i][j]);
    }

    putchar('\n');
  }
}
