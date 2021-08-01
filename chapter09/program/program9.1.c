#include <stdio.h>

#define SIZE ((int)(sizeof(array) / sizeof(array[0])))

void selection_sort(int a[], int n);

int main() {
  int array[] = {34, 456, 6, 8, 889, 67, 23, 9, 67, 678};
  selection_sort(array, SIZE);

  for (int i = 0; i < SIZE; i++)
    printf("%d ", array[i]);

  return 0;
}

void selection_sort(int a[], int n) {
  if (n > 1) {
    int index, max_index = 0, temp;
    for (index = 0; index < n; index++) {
      if (a[index] > a[max_index])
        max_index = index;
    }

    temp = a[n - 1];
    a[n - 1] = a[max_index];
    a[max_index] = temp;

    selection_sort(a, n - 1);
  }
}