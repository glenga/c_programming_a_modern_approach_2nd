#include <stdio.h>

int main() {
  int a[4][10];

  int num = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 10; j++)
      a[i][j] = num++;
  }

  int *p1 = &a[0][0];
  for (int i = 0; i < 4; i++) {
    printf("%4d", *p1++);
  }

  printf("\n\n");

  int *p2 = a[0]; // a[0] 是一维数组,包含10个元素
  for (int i = 0; i < 4; i++) {
    printf("%4d", *p2++);
  }

  // int *p= a[0 + 3];   取第三行
  // int *p = a[0] +3; 0行偏移3个元素的位置

  printf("\n\n");

  // initialization of 'int *' from incompatible pointer type 'int (*)[10]'
  // int *p2 = &a[0];
  int(*p3)[10] = &a[0];
  for (int i = 0; i < 4; i++) {
    printf("%4d", (*p3++)[0]);
  }

  printf("\n\n");

  int(*p4)[10] = a;
  for (int i = 0; i < 4; i++) {
    printf("%4d", (*p4++)[0]);
  }

  printf("\n\n");

  return 0;
}