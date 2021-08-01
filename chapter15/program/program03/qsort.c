#include "quicksort.h"
#include <stdio.h>

#define N 10

int main() {
  int a[N];

  printf("Enter %d numbers to be sorted: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  quick_sort(a, 0, N - 1);

  printf("In sorted order: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
  return 0;
}

// test: 9 16 47 82 4 66 12 3 25 51