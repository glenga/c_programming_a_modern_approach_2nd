#include <stdbool.h>
#include <stdio.h>

#define N 10

void quick_sort(int *low, int *high);
int *split(int *low, int *high);

int main() {
  int a[N];

  printf("Enter %d numbers to be sorted: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  quick_sort(a, a + N - 1);

  printf("In sorted order: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
  return 0;
}

void quick_sort(int *low, int *high) {
  int *middle;
  if (low >= high)
    return;

  middle = split(low, high);
  quick_sort(low, middle - 1);
  quick_sort(middle + 1, high);
}

int *split(int *low, int *high) {
  int part_element = *low;
  while (true) {
    while (low < high && part_element <= *high)
      high--;

    if (low >= high)
      break;

    *low++ = *high;

    while (low < high && *low <= part_element)
      low++;

    if (low >= high)
      break;

    *high-- = *low;
  }

  *high = part_element;
  return high;
}

// test: 9 16 47 82 4 66 12 3 25 51