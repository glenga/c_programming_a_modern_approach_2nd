#include <stdio.h>

#define SIZE ((int)(sizeof(a) / sizeof(a[0])))

int main() {
  int a[10];

  printf("Enter %d numbers: ", SIZE);

  for (int i = 0; i < SIZE; i++)
    scanf("%d", &a[i]);

  printf("In reverse order: ");

  for (int i = SIZE - 1; i >= 0; i--)
    printf("%6d", a[i]);

  printf("\n");

  return 0;
}

// Enter 10 numbers: 34 82 49 102 7 94 23 11 50 31