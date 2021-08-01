#include <stdio.h>

int max(int a[], int n);
int min(int a[], int n);
float average(int a[], int n);

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("The max of array is: %d\n", max(array, 10));
  printf("The min of array is: %d\n", min(array, 10));
  printf("The average of array is: %.2f\n", average(array, 10));
  return 0;
}

int max(int a[], int n) {
  int max = a[0];
  for (int i = 1; i < 10; i++) {
    if (a[i] > max)
      max = a[i];
  }

  return max;
}
int min(int a[], int n) {
  int min = a[0];
  for (int i = 1; i < 10; i++) {
    if (a[i] < min)
      min = a[i];
  }

  return min;
}

float average(int a[], int n) {
  float sum = 0;
  for (int i = 0; i < 10; i++)
    sum += a[i];

  return sum / n;
}
