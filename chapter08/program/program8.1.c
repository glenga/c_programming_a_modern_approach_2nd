#include <stdbool.h>
#include <stdio.h>

int main() {
  bool digit_seen[10] = {0};

  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  printf("Repeated digit(s): ");
  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit])
      printf("%3d", digit);
    else
      digit_seen[digit] = true;

    n /= 10;
  }

  printf("\n");
  return 0;
}

// Enter a number: 939577