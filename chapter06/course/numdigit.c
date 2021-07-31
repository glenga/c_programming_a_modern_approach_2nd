#include <stdio.h>

int main(void) {
  int num, n = 0;
  printf("Enter a nonnegative integer: ");
  scanf("%d", &num);

  do {
    num /= 10;
    n++;
  } while (num > 0);

  printf("The number has %d digit(s)", n);

  return 0;
}

// Enter a nonnegative integer: 60