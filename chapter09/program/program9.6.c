#include <math.h>
#include <stdio.h>

double calculate_polynomial(double x);

int main() {
  double x;
  printf("Enter the value of x: ");
  scanf("%lf", &x);

  printf("the  value of polynomial: %lf\n", calculate_polynomial(x));

  return 0;
}

double calculate_polynomial(double x) {
  return 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * x - 6;
}

// Enter the value of x: 4