#include <stdbool.h>
#include <stdio.h>

int main() {
  int digit_seen[10] = {0};

  int digit;
  long long n;

  printf("Enter a number: ");
  scanf("%I64d", &n);

  while (n > 0) {
    digit = n % 10;
    digit_seen[digit]++;
    n /= 10;
  }

  printf("Digit:\t\t");
  for (int i = 0; i < 10; i++)
    printf("%4d", i);

  printf("\nOccurrences:\t");
  for (int i = 0; i < 10; i++)
    printf("%4d", digit_seen[i]);

  printf("\n");
  return 0;
}

// Enter a number: 4127109222