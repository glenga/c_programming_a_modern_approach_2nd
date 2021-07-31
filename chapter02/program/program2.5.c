#include <stdio.h>

int main(void) {
  double x, result;
  printf("Enter your x: ");
  scanf("%d", &x);

  result = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x +
           7 * x - 6;

  printf("polynomial(3x^5+2x^4-5x^3-x^2+7x-6) value is: %.2f", result);

  return 0;
}