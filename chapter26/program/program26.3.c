#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int compare(const void *p, const void *q);

int main() {

  int arr[N];

  for (int i = 0; i < N; i++)
    arr[i] = N - i;

  clock_t start_clock = clock();

  qsort(arr, N, sizeof(int), compare);

  printf("Time to sort %d ints: %ld sec.\n", N,
         (clock() - start_clock) / CLOCKS_PER_SEC);

  return 0;
}

int compare(const void *p, const void *q) { return *(int *)p - *(int *)q; }