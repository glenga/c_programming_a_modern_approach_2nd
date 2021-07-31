#include <stdio.h>

int main(void) {
  double sum = 0;
  float n;

  printf("\nThe program prints a table of squares.\n");
  printf("Enter number of entries in table: ");

  while (1) {
    scanf("%f", &n);
    if (n)
      sum += n;
    else
      break;
  }

  printf("The sum is: %.4f", sum);

  return 0;
}

// Enter number of entries in table: 1000 2000 3000 0