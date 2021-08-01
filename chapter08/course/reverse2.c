#include <stdio.h>

int main() {
  int n;
  printf("How many numbers do you want to reverse?: ");
  scanf("%d", &n);

  // 变长数组, c99 only
  int a[n];

  printf("Enter %d numbers: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("In reverse order: ");
  for (int i = n - 1; i >= 0; i--)
    printf(" %d", a[i]);

  printf("\n");

  return 0;
}

// How many numbers do you want to reverse?: 10
// Enter 10 numbers: 34 82 49 102 7 94 23 11 50 31