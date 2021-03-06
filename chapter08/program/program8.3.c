#include <stdbool.h>
#include <stdio.h>

int main() {
  while (true) {
    bool digit_seen[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    if (n < 0)
      break;

    while (n > 0) {
      digit = n % 10;
      if (digit_seen[digit])
        break;
      digit_seen[digit] = true;

      n /= 10;
    }

    if (n > 0)
      printf("Repeated digit.\n");
    else
      printf("No repeated digit.\n");
  }

  return 0;
}

// Enter a number: 100000000000000001