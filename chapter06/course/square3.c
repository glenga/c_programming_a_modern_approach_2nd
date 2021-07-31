#include <stdio.h>

int main() {
  int i, n, odd, square;
  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");

  scanf("%d", &n);

  i = 1;
  odd = 3;
  // 平方表的基础增量odd, (n+1)^2 = n^2 + odd +2
  for (square = 1; i <= n; odd += 2) {
    printf("%10d%10d\n", i, square);
    ++i;
    square += odd;
  }

  return 0;
}

// Enter number of entries in table: 5