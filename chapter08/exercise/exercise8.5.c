#include <stdio.h>

int main() {
  int fib_number[40] = {1, 1};
  for (int i = 2; i < 40; i++)
    fib_number[i] = fib_number[i - 2] + fib_number[i - 1];

  for (int i = 0; i < 40; i++)
    printf(" %d", fib_number[i]);

  printf("\n");

  return 0;
}