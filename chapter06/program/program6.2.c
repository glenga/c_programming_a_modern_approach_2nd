#include <stdio.h>

// 最大公约数 GCD
int main(void) {
  int m, n, remainder;
  printf("Enter two integers: ");
  scanf("%d%d", &m, &n);

  while (n != 0) {
    remainder = m % n;
    m = n;
    n = remainder;
  }

  printf("Greatest common divisor: %d", m);

  return 0;
}

// Enter two integers: 12 28