#include <stdio.h>

int main(void) {
  int num, n = 0;
  printf("Enter a number: ");
  scanf("%d", &num);

  int s = num;
  do {
    s /= 10;
    n++;
  } while (s > 0);

  printf("The num %d has %d digit(s).\n", num, n);
  return 0;
}

// Enter a number: 374