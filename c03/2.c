/*
formats, using tab, user input
*/

#include <stdio.h>

int main(void)
{
  int item, m, d, y;
  float price;

  printf("Enter item number: ");
  scanf("%d", &item);

  printf("Enter unit price: ");
  scanf("%f", &price);

  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &m, &d, &y);

  printf("\nItem\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\t\n%-d\t\t$%7.2f\t%d/%d/%d\n", item, price, m, d,y);

  return 0;
}
