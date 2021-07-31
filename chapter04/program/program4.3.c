#include <stdio.h>

int main(void) {
  int a, b, c;
  printf("Enter a two-digit number: ");
  scanf("%1d%1d%1d", &a, &b, &c);
  printf("%d%d%d", c, b, a);
  return 0;
}

// Enter a two-digit number: 809