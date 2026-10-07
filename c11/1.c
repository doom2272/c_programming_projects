/*
*modify to include pay_ammount.
* user enters a dollar ammount, then the ammount is broken down into 20, 10, 5 and 1 dollar bills.
*/

#include <stdio.h>

void pay_ammount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {

    int money = 0, twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &money);

    pay_ammount(money, &twenties, &tens, &fives, &ones);

    printf("$20 bills: %d\n", twenties);

    printf("$10 bills: %d\n", tens);

    printf(" $5 bills: %d\n", fives);

    printf(" $1 bills: %d\n", ones);

    return 0;
}

void pay_ammount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
  *twenties = dollars / 20;
  dollars -= *twenties * 20;

  *tens = dollars / 10;
  dollars -= *tens * 10;

  *fives = dollars / 5;
  dollars -= *fives * 5;

  *ones = dollars;
}
