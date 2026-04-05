//modify cap2 project 8, to also ask user to enter the number of payments and then displays the balance remaining after each of those payments.

#include <stdio.h>

int main(void) {

  int n, i; //n indicates the number of months already paid.

 float loan = 0.0f,
       rate = 0.0f,
       payment = 0.0f;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &rate);

    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    printf("Enter the number of payments (months paid): ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {

    loan = loan - payment + (loan * rate / 100.0 / 12.0);

    printf("Balance remaining after payment %d: $%.2f\n", i, loan);

    }

}
