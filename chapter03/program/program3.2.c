#include <stdio.h>

int main(void) {
  int month, day, year, number;
  float price;

  printf("Enter item number: ");
  scanf("%d", &number);
  printf("Enter unit price: ");
  scanf("%f", &price);
  printf("Enter purchase data (mm/dd/yyyy): ");
  scanf("%d /%d /%d", &month, &day, &year);

  printf("Item\t\tUnit\t\tPurchase\n");
  printf("\t\tPrice\t\tDate\n");
  printf("%d\t\t$%7.2f\t%.2d%.2d%.4d\n", number, price, month, day, year);

  return 0;
}

// Enter item number: 583
// Enter unit price: 13.5
// Enter purchase data (mm/dd/yyyy): 10/24/2010