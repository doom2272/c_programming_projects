/*
 * prints a square using a 2d array, the length is provided by the user.
 * places number 1 in the middle of row 0, then place the remaining numbers by moving 1 row up and one column over.
 * we should wrap around when we are the edge (when in row 1, go to n - 1; instead of column n go to column 0).
 * if a position in the element is occupied, put the number directly below the previously stored number.
 */

#include <stdio.h>

int main(void)
{

  int n, row, col, current_row, current_col, width = 0, c;

  printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &n);

  if (n % 2 == 0 || n < 0 || n > 99){ //ensures user enters an odd number between 1 - 99
    printf("Size should be an odd number and range between 1 - 99\n");
    return 1;
  }

  c = n * n; //this callculates the largest number in our magic square

  while (c != 0) { //this loop uses the largest number to determine the length of our numbers. eg if user provides n = 3, our largest number would be 9, which is 1 decimal. so we know our number width is 1. but if n = 5, our number width would be 2.
    c = c / 10;
    width++;
  }

  int square[n][n]; //creates a variable length array with rows and columns equal to n

  for (int i = 0; i < n; i++) { // puts 0's as elemts in the entire array
    for (int j = 0; j < n; j++) {
      square[i][j] = 0;
    }
  }

  row = 0; col = n / 2; //our starting point is at row 0, in the middle column
  square[row][col] = 1;

  int num = 2;

  while (num <= n * n) { //as long as we dont exceed our square, which is the largest nimber
    current_row = row;
    current_col = col;

    if ((current_row - 1) < 0) row = n - 1;// if our next move is past our before our first row, wrap around
    else row = current_row - 1; //if its not out of bounds keep moving up a row

    if ((current_col + 1) >= n) col = 0; // if our next move is past our last column, wrap around to the first column
    else col = current_col + 1; //if not keep moving one column over

    if (square[row][col] == 0) square[row][col] = num++; //if our next move has a zero populate it with a number, then increment num
    else { // if we already filled the next spot, remain on the same column but move a row down
      if (current_row + 1 >= n) 
        square[row = 0][col = current_col] = num++;
      else 
        square[row = current_row + 1][col = current_col] = num++;
    }
  }

  for (int i = 0; i < n; i++) { //prints our magic square
    for (int j = 0; j < n; j++){
      printf("%*d ", width, square[i][j]); //the asterix uses the width variable to adjust our minimum number of digits to print. so if our largest number is 9, print 1 digit, if its 25, print a minimum of 2 digits, if its 121, print a minimumof 3 digits for each element in our array
    }
    putchar('\n');
  }
  return 0;
}
