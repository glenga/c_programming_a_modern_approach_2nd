#include <stdio.h>

int main(void) {
  int i, j;

  for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
    printf("%d ", i);

  printf("\n\n");

  for (int i = 10; i >= 1; i /= 2)
    printf("%d ", i++);

  return 0;
}