#include <stdio.h>

void swap(int *p, int *q);

int main() {
  int n1 = 10, n2 = 100;
  swap(&n1, &n2);

  printf("n1=%d, n2=%d\n", n1, n2);

  return 0;
}

void swap(int *p, int *q) {
  int tmp = *p;
  *p = *q;
  *q = tmp;
}