/*
* user enters a dollar ammount, then the ammount is broken down into 20, 10, 5 and 1 dollar bills.
*/

#include <stdio.h>

int main(void) {

    int money = 0;

    printf("Enter a dollar amount: ");
    scanf("%d", &money);

    printf("$20 bills: %d\n", money/20);
    money =  money - ((money/20) * 20);

    printf("$10 bills: %d\n", money/10);
    money = money - ((money/10) * 10);

    printf(" $5 bills: %d\n", money/5);
    money = money - ((money/5) * 5);

    printf(" $1 bills: %d\n", money);

    return 0;
}
