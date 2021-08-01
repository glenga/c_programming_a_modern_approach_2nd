#include <complex.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
  double a =5, b = 2, c = 1;

  double complex discriminant_sqrt = csqrt(b * b - 4 * a * c);
  double complex root1 = (-b + discriminant_sqrt) / (2 * a);
  double complex root2 = (-b - discriminant_sqrt) / (2 * a);

  if (cimag(root1) == 0)
    printf("root1 = %g\n", creal(root1));
  else
    printf("root1 = %g %c %gi\n", creal(root1), cimag(root1) < 0 ? '-' : '+',
           fabs(cimag(root1)));
  if (cimag(root2) == 0)
    printf("root2 = %g\n", creal(root2));
  else
    printf("root2 = %g %c %gi\n", creal(root2), cimag(root2) < 0 ? '-' : '+',
           fabs(cimag(root2)));

  return 0;
}