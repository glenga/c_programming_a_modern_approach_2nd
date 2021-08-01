#include <stdio.h>

int num_digits(int n);

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("The number has %d digit(s).\n", num_digits(n));
  return 0;
}

int num_digits(int n) {
  int count = 0;
  do {
    n /= 10;
    count++;
  } while (n > 0);

  return count;
}