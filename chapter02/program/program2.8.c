#include <stdio.h>

int main(void) {
  float amount, rate, payment;
  printf("Enter amount of loan: ");
  scanf("%f", &amount);
  printf("Enter interest rate:");
  scanf("%f", &rate);
  printf("Enter monthly payment:");
  scanf("%f", &payment);

  amount = (amount - payment) + amount * rate / 100 / 12;
  printf("Balance remaining after first payment: $%.2f\n", amount);

  amount = (amount - payment) + amount * rate / 100 / 12;
  printf("Balance remaining after second payment: $%.2f\n", amount);

  amount = (amount - payment) + amount * rate / 100 / 12;
  printf("Balance remaining after third payment:  $%.2f\n", amount);

  return 0;
}