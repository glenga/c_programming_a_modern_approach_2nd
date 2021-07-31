#include <stdio.h>

int main() {
  // 根据编译器提示可以知道正确的占位符为%I64d
  printf("sizeof(short)\t\t:  %I64d\n", sizeof(short));
  printf("sizeof(int)\t\t:  %I64d\n", sizeof(int));
  printf("sizeof(long)\t\t:  %I64d\n", sizeof(long));
  printf("sizeof(float)\t\t:  %I64d\n", sizeof(float));
  printf("sizeof(double)\t\t: %I64d\n", sizeof(double));
  printf("sizeof(long double)\t:  %I64d\n", sizeof(long double));

  return 0;
}