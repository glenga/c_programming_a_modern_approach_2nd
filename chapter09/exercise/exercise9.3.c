#include <stdio.h>

int GCD(int m, int n);

int main() {
  int m, n;
  printf("Enter two integers: ");
  scanf("%d /%d", &m, &n);

  printf("Greatest common divisor: %d", GCD(m, n));
  return 0;
}

// 最大公约数
int GCD(int m, int n) {
  int remainder;

  while (n > 0) {
    remainder = m % n;
    m = n;
    n = remainder;
  }

  return m;
}

// int GCD(int m, int n) { return n <= 0 ? m : GCD(n, m % n); }