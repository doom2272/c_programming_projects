/*
* modifies project 2 so that now user is prompted to enter the radius of a sphere
*/

#include <stdio.h>

int main(void) {

    int r = 0;

    printf("Enter radius: ");
    scanf("%d", &r);

    printf("\nSphere volume: %.2f cubic meters\n",
           4.0f/3.0f * 3.14f * r * r * r);
    return 0;
}
