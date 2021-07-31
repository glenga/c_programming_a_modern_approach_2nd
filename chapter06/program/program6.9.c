#include <stdio.h>

int main(void) {
  float loan, rate, payment;
  int num_of_pay;

  printf("Enter amount of loan: ");
  scanf("%f", &loan);

  printf("Enter interest rate: ");
  scanf("%f", &rate);

  printf("Enter monthly payment: ");
  scanf("%f", &payment);

  printf("Enter number of payment: ");
  scanf("%d", &num_of_pay);

  for (int i = 1; i <= num_of_pay; i++) {
    printf("Balance remaining after %d(th) payment: $%.2f\n", i,
           loan = loan - payment + loan * rate / 100.0f / 12.0f);
  }

  return 0;
}

// Enter amount of loan: 20000.00
// Enter interest rate: 6.0
// Enter monthly payment: 1386.6
// Enter number of payment: 10