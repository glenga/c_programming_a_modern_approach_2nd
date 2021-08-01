#include <stdio.h>

double average(double a, double b) { return (a + b) / 2; }

int main() {
  double x, y, z;

  printf("Enter three double numbers: ");
  scanf("%lf%lf%lf", &x, &y, &z);
  printf("Average of %g and %g\t:  %g\n", x, y, average(x, y));
  printf("Average of %g and %g\t:  %g\n", x, z, average(x, z));
  printf("Average of %g and %g\t:  %g\n", y, z, average(y, z));

  return 0;
}

// Enter three double numbers: 3.5 9.6 10.2