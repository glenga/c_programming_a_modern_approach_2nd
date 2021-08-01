#include <stdio.h>

#define N 10

int main() {
  int a[N], *p;

  printf("Enter %d number: ", N);

  for (p = a; p < a + N; p++)
    scanf("%d", p);

  printf("In reverse order: ");
  for (p = a + N - 1; p >= a; p--)
    printf(" %d", *p);

  printf("\n");

  return 0;
}

// Enter 10 number: 34 456 89 678 45 12 67 890 4566 87