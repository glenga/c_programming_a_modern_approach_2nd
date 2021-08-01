#include <stdio.h>

#define SIZE ((int)sizeof(a) / sizeof(a[0]))

double inner_product(double a[], double b[], int n);

int main() {
  double a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double b[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

  printf("The result: %lf\n", inner_product(a, b, SIZE));

  return 0;
}

double inner_product(double a[], double b[], int n) {
  double sum;
  for (int i = 0; i < n; i++)
    sum += a[i] * b[i];

  return sum;
}