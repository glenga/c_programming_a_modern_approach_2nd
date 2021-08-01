#include <stdio.h>
#include <stdlib.h>

// 函数返回指向数组的指针
int (*foo(int))[5]; // 声明

int list[5] = {0};

int main() {
  typedef int array[5];
  typedef array *fn_ret_ptr(int);

  fn_ret_ptr *fn_ptr = foo;

  array *ptr = (*fn_ptr)(100);
  printf("%p  %d \n\n", ptr, **ptr);

  for (int i = 0; i < 5; i++) {
    printf("%d ", list[i]);
  }

  printf("\n");
  return 0;
}

// 函数返回指向数组的指针
int (*foo(int n))[5] { // 定义
  list[0] = n;
  return &list;
}