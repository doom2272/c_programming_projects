/*
* modifies project 5, so that the polynimial is evaluated using Horner's Rule:
* ((((3x +2)x - 5)x - 1)x + 7)x - 6
*/

#include <stdio.h>

int main(void) {

    int x = 0;

    printf("Enter value for x: ");
    scanf("%d", &x);
    printf("Result: %d\n",
           ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);

    return 0;
}
