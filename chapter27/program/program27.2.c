#include <math.h>
#include <stdio.h>

int main(void) {
  double real, imag, r, theta;

  printf("Enter real and imaginary value of complex number: ");
  scanf("%lf%lf", &real, &imag);

  r = sqrt(real * real + imag * imag);
  theta = atan(real / imag);

  printf("r = %g\ntheta = %g rads\n", r, theta);
  return 0;
}

