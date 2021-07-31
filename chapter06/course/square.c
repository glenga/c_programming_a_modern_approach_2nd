#include <stdio.h>

int main(void) {

  int i = 1, n;
  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  while (i <= n) {
    printf("%d\t%d\n", i, i * i);
    i++;
  }

  return 0;
}

// Enter number of entries in table: 5