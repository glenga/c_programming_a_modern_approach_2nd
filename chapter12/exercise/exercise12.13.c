#include <stdio.h>

#define N 10

void init_ident(int n, double ident[n][n]) {
  double *p = &ident[0][0];
  int zeros = n;

  while (p < &ident[0][0] + n * n) {
    if (zeros == n) {
      *p = 1;
      zeros = 0;
    } else {
      *p = 0;
      zeros++;
    }
    p++;
  }
}

int main() {
  double array[N][N];

  init_ident(10, array);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%.2f ", array[i][j]);

    printf("\n");
  }

  return 0;
}