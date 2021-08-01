#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);
// void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main() {
  int array[] = {768, 34, 456, 768, 89, 5, 6, 78, 344, 567, 568, 354};

  int largest, second_largest;
  find_two_largest(array, sizeof(array) / sizeof(array[0]), &largest,
                   &second_largest);

  printf("largest: %d, second_largest: %d\n", largest, second_largest);
  return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
  // 第一遍找最大值
  *largest = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > *largest)
      *largest = a[i];
  }

  // 第二遍排除最大值,找第二大的
  *second_largest = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > *second_largest && a[i] != *largest)
      *second_largest = a[i];
  }
}

// void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
//   const int *p = a;
//   *largest = *a;
//   while (++p < a + n) {
//     if (*p > *largest)
//       *largest = *p;
//   }

//   p = a;
//   *second_largest = 0;
//   while (p++ < a + n && *p != *largest) {
//     if (*p > *second_largest)
//       *second_largest = *p;
//   }
// }