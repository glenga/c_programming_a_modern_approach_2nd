#include <stdio.h>

int main(void) {
  int n;
  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");

  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    printf("%d\t%d\n", i, i * i);

  return 0;
}

// Enter number of entries in table: 5