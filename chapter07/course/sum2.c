#include <stdio.h>

int main(void) {
  long sum = 0, n;

  printf("The program prints a table of squares.\n");
  printf("Enter number of entries in table: ");

  while (1) {
    scanf("%ld", &n);
    if (n)
      sum += n;
    else
      break;
  }

  printf("The sum is: %ld", sum);

  return 0;
}

// Enter number of entries in table: 10000 20000 30000 0