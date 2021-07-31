#include <stdio.h>

int main(void) {
  int m, n, r, tmp_m, tmp_n;
  printf("Enter a fraction: ");
  scanf("%d /%d", &m, &n);

  tmp_m = m;
  tmp_n = n;

  while (tmp_n != 0) {
    r = tmp_m % tmp_n;
    tmp_m = tmp_n;
    tmp_n = r;
  }

  printf("In lowest terms: %d/%d\n", m / tmp_m, n / tmp_m);

  return 0;
}

// Enter a fraction: 6/12