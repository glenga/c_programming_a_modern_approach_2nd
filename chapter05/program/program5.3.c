#include <stdio.h>

int main(void) {
  int stock_quantity;

  float price_per_share, commission, opponent_commission;

  printf("Enter the stock number and price: ");
  scanf("%d %f", &stock_quantity, &price_per_share);

  float transaction_amount = (float)stock_quantity * price_per_share;

  if (transaction_amount < 2500.00f)
    commission = 30.00f + transaction_amount * .017f;
  else if (transaction_amount < 6250.00f)
    commission = 56.00f + transaction_amount * .0066f;
  else if (transaction_amount < 20000.00f)
    commission = 76.00f + transaction_amount * .0034f;
  else if (transaction_amount < 50000.00f)
    commission = 100.00f + transaction_amount * .0022f;
  else if (transaction_amount < 500000.00f)
    commission = 155.00f + transaction_amount * .0011f;
  else
    commission = 255 + transaction_amount * .0009f;

  if (commission < 39.00f)
    commission = 39.00f;

  printf("commission: %.2f\t", commission);

  if (stock_quantity < 2000)
    opponent_commission = 33.0f + stock_quantity * .03f;
  else
    opponent_commission = 33.0f + stock_quantity * .02f;

  printf("opponent commission: %.2f\n", opponent_commission);

  return 0;
}

// Enter value of trade: 30000 12