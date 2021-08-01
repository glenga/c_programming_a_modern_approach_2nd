#include <math.h>
#include <stdio.h>

int main() {
  double p, r;
  int t;
  printf("Enter amount of dollars, rate and years: ");
  scanf("%lf%*[ ,]%lf%*[ ,]%d", &p, &r, &t);

  printf("Total compounded: $ %.2lf\n", p * exp(r / 100 * t));
  return 0;
}

// test: Enter amount of dollars, rate and years: 1000, 10, 6