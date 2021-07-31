#include <stdio.h>

int main(void) {
  float trade_value, commission;
  printf("Enter value of trade: ");
  scanf("%f", &trade_value);

  if (trade_value < 2500.00f)
    commission = 30.00f + trade_value * .017f;
  else if (trade_value < 6250.00f)
    commission = 56.00f + trade_value * .0066f;
  else if (trade_value < 20000.00f)
    commission = 76.00f + trade_value * .0034f;
  else if (trade_value < 50000.00f)
    commission = 100.00f + trade_value * .0022f;
  else if (trade_value < 500000.00f)
    commission = 155.00f + trade_value * .0011f;
  else
    commission = 255 + trade_value * .0009f;

  if (commission < 39.00f)
    commission = 39.00f;

  printf("Commission: $%.2f\n", commission);

  return 0;
}

// Enter value of trade: 30000