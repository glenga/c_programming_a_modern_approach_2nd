#include <stdio.h>

int main(void) {
  int sum = 0, n;

  printf("The program sums a series of integers.\n");
  printf("Enter integers (0 to terminate): ");

  while (1) {
    scanf("%d", &n);
    if (n)
      sum += n;
    else
      break;
  }

  printf("The sum is: %d", sum);

  return 0;
}

// Enter integers (0 to terminate): 8 23 71 5 0