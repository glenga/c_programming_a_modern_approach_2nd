#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n) {
  if (n <= 1)
    return false;

  int divisor;

  for (divisor = 2; divisor * divisor <= n; divisor++) {
    if (n % divisor == 0)
      return false;

    return true;
  }
  return 0;
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if (is_prime(n))
    printf("Prime.\n");
  else
    printf("Not Prime.\n");
}


// Enter a number: 34