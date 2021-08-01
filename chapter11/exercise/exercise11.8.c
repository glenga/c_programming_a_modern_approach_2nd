#include <stdio.h>

int *find_largest(int a[], int n);

int main() {
  int array[] = {768, 34, 456, 768, 89, 5, 6, 78, 344, 567, 568, 354};

  int *max = find_largest(array, sizeof(array)/ sizeof(array[0]));

  printf("The max of array is: %d\n", *max);

  return 0;
}

int *find_largest(int a[], int n) {
  int *max = &a[0];
  
  for (int i = 0; i < n; i++) {
    if (a[i] > *max)
      max = &a[i];
  }

  return max;
}