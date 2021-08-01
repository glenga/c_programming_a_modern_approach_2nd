#include <math.h>
#include <stdio.h>

int main(void) {
  double real, imag, r, theta;

  printf("Enter r and theta (in radians): ");
  scanf("%lf%lf", &r, &theta);

  real = r * cos(theta);
  imag = r * sin(theta);

  printf("%g %c %gi\n", real, imag < 0 ? '-' : '+', imag);
  return 0;
}