/*
 * generates a random walk (replaces . with letters) across a 10 * 10 array filled with periods (.) .
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(void)
{
  char area[10][10] = {{'.'}};
  int next_r, next_c, r = 0, c = 0, move;

  for (int i = 0; i < N; i++) { // adds a period to each element in area
    for (int j = 0; j < N; j++) {
      area[i][j] = '.';
    }
  }

  srand((unsigned) time(NULL)); // ensure rand has a different starting point everytime its called

  area[0][0] = 'A'; //always start path from area[0][0]

  for (char ch = 'B'; ch <= 'Z'; ch++) { 

    bool tries[4] = {false}; //used to track if all 4 directions are tried 
    bool moved = false; // used to track if program ended prematurely, due to lack of possible move

    while (!tries[0] || !tries[1] || !tries[2] || !tries[3]) { //as long as all possible moves have not been exhausted
      move = rand() % 4; // generate random move from 4 directions
      tries[move] = true; // mark direction from rand as already checked

      if (move == 0) { // if move is 0, that means go up
        next_r = r - 1; // r is our current row
        next_c = c; // c is our current column
      }
      else if (move == 1) { //go down
        next_r = r + 1;
        next_c = c;
      }
      else if (move == 2) { //go left
        next_r = r;
        next_c = c - 1;
      }
      else { // go right
        next_r = r;
        next_c = c + 1;
      }

      if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < N && area[next_r][next_c] == '.') { // as long as our next move is within array boundary and the element there is a period(.)
        r = next_r; // we can safely move to the next row
        c = next_c; // we can safely move to the next column
        area[r][c] = ch; // then add a letter 

        moved = true; // signals we found valid move so we should move to the next letter
        break;
      }
    }

    if (moved == false) // this means no valid move was available, so exit the program prematurely
      break;
  }


  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      putchar(area[i][j]);
      putchar(' ');
    }
    putchar('\n');
  }

  return 0;
}
