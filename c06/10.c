//modifies project 9, cap5; now the user is continuosly prompted to enter a date. 0/0/0 is used to exit the program. The program then displays the earliest date out of all those entered..

#include <stdio.h>

int main(void)
{
  int m, m2, d, d2, y, y2;

  printf("Enter a date (mm/dd/yy): ");
  scanf("%d/%d/%d", &m, &d, &y); //assume the first date is the earliest

  while (1) { //while (1) is best used with break for "loop until user enters 0" scenarios
    
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    if (m2 == 0 && d2 == 0 && y2 == 0) break; //if user enters 0/0/0 exit loop

    if (y2 < y) {
      m = m2; d = d2; y = y2;
     }
    else if (y2 == y && m2 < m) {
      m = m2; d = d2; y = y2;
     }
    else if (y2 == y && m2 == m && d2 < d) {
      m = m2; d = d2; y = y2;
     }

  }

  printf("%d/%d/%.2d is the earliest date\n", m, d, y);

}
