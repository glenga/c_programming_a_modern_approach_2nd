#include <stdio.h>

int main(void) {
  int i;
  float x;

  i = 40;
  x = 839.21f;

  printf("%d|%5d|%-5d|%5.3d\n", i, i, i, i); // 位数不够补0

  printf("%10.3f|%10.3e|%-10g|\n", x, x, x); // g自动格式 既可以是定点

  return 0;
}