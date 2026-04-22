/*
 * prints a square using a 2d array, the length is provided by the user.
 * places number 1 in the middle of row 0, then place the remaining numbers by moving 1 row up and one column over.
 * we should wrap around when we are the edge (when in row 1, go to n - 1; instead of column n go to column 0).
 * if a position in the element is occupied, put the number directly below the previously stored number.
 */

#include <stdio.h>

int main(void)
{

  int n, num = 1, row, col, width = 0, c;

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
  
  while (num <= n * n) { //as long as we dont exceed our square, which is the largest nimber
    if (square[row][col] == 0){ //enssure we only print if the element is 0, so we don't overwrite already written elements
      square[row][col] = num; //write the current number in the element
      row--; //then move one row up
      col++;// and one column over (to the right)
      if (row < 0) //wrap aroud if we are over the first row
        row = n - 1;
      if (col > n - 1) //wrap around if we are outside the last column
        col = 0;
    }
    else { //if the element is not a zero, that means we have already written here
      row = row + 2; //move one row down from our previous row
      col--;// but at the same cloumn(so we effectively move down one row). we decrement because to move to our previous column we need to undo the increment that moves our column to the next column
      if (row > n - 1) //wrap around if we move past the last row
        row = row - n;
      if (col < 0) //wrap around if we are trying to move to a position before our first column
        col = col + n;
      square[row][col] = num; //write our to the current number below the previous postion sice our intended position was already written to
      row--; //move up a rpw
      col++; //move to the next column (we are doing this to indentify our next position since we skipped the if statement above that was supposed to update the position for us)
      if (col > n - 1)
        col = 0;
    }
    num++; //only increment our number if we have already written the current one somewhere
  }

  for (int i = 0; i < n; i++) { //prints our magic square
    for (int j = 0; j < n; j++){
      printf("%*d ", width, square[i][j]); //the asterix uses the width variable to adjust our minimum number of digits to print. so if our largest number is 9, print 1 digit, if its 25, print a minimum of 2 digits, if its 121, print a minimumof 3 digits for each element in our array
    }
    putchar('\n');
  }

  return 0;
}
