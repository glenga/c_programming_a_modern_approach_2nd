#include <stdbool.h>
#include <stdio.h>

#define N 10

void quick_sort(int a[], int low, int high);
int split(int a[], int low, int high);

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

void quick_sort(int a[], int low, int high) {
  int middle;
  if (low >= high)
    return;

  middle = split(a, low, high);
  quick_sort(a, low, middle - 1);
  quick_sort(a, middle + 1, high);
}

int split(int a[], int low, int high) {
  int part_element = a[low];
  while (true) {
    while (low < high && part_element <= a[high])
      high--;

    if (low >= high)
      break;

    a[low++] = a[high];

    while (low < high && a[low] <= part_element)
      low++;

    if (low >= high)
      break;

    a[high--] = a[low];
  }

  a[high] = part_element;
  return high;
}

// test: 9 16 47 82 4 66 12 3 25 51