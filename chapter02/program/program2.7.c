#include <stdio.h>

int main(void) {
  int amount;
  printf("Enter a dollar amount: ");
  scanf("%d", &amount);

  // $20
  int d20 = amount / 20;
  int balance = amount % 20;

  // $10
  int d10 = balance / 10;
  balance = balance % 10;

  // $5
  int d5 = balance / 5;
  balance = balance % 5;

  // $1
  int d1 = balance;

  printf("$20 bills: %d\n", d20);
  printf("$10 bills: %d\n", d10);
  printf(" $5 bills: %d\n", d5);
  printf(" $1 bills: %d\n", d1);

  return 0;
}