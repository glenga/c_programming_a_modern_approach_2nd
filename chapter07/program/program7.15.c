#include <stdio.h>

int main() {
  // short x = 1, result;
  // printf("Enter a positive integer: ");
  // scanf("%d", &x);

  for (short i = 1, result = 1; result > 0; i++) {
    printf("Factorial of %2d: %d\n", i, result *= i);
    if (result < 0)
      printf("\n使用short类型存储, i的最大值为: %d\n\n", i - 1);
  }

  for (int i = 1, result = 1; result > 0; i++) {
    printf("Factorial of %2d: %d\n", i, result *= i);
    if (result < 0)
      printf("\n使用int类型存储, i的最大值为: %d\n\n", i - 1);
  }

  for (long i = 1, result = 1; result > 0; i++) {
    printf("Factorial of %2ld: %ld\n", i, result *= i);
    if (result < 0)
      printf("\n使用long类型存储, i的最大值为: %ld\n\n", i - 1);
  }

  for (long long i = 1, result = 1; result > 0; i++) {
    printf("Factorial of %I64d: %I64d\n", i, result *= i);
    if (result < 0)
      printf("\n使用long long类型存储, i的最大值为: %I64d\n\n", i - 1);
  }

  // ============================================================
  float result = 1.0f;
  int fi;
  for (fi = 1; result < __FLT_MAX__; fi++) { // __FLT_MAX__
    result *= fi;
    printf("Factorial of %2d: %g\n", fi, result);
  }
  printf("\n使用float类型存储, i的最大值为: %d\n\n", fi - 2);

  double result1 = 1.0;
  int di;
  for (di = 1; result1 < __DBL_MAX__; di++) { // __DBL_MAX__
    result1 *= di;
    // printf("Factorial of %3d: %g\n", di, result1);
  }
  printf("\n使用double类型存储, i的最大值为: %d\n\n", di - 2);

  long double result2 = 1.0;
  int ldi;
  for (ldi = 1; result2 < __LDBL_MAX__; ldi++) { // __LDBL_MAX__
    result2 *= ldi;
    // printf("Factorial of %4d: %Lg\n", ldi, result2);
  }
  printf("\n使用long double类型存储, i的最大值为: %d\n\n", ldi - 2);

  return 0;
}