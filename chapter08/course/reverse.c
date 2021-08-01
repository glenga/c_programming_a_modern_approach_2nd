#include <stdio.h>

#define N 10

int main() {
  int a[N];

  printf("Enter %d numbers: ", N);

  for (int i = 0; i < N; i++)
    scanf("%d", &a[i]);

  printf("In reverse order: ");

  for (int i = N - 1; i >= 0; i--)
    printf("%6d", a[i]);

  printf("\n");

  return 0;
}

// Enter 10 numbers: 34 82 49 102 7 94 23 11 50 31