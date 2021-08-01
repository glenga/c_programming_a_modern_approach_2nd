#include <stdio.h>
#include <stdlib.h>

int main() {
  // 函数指针数组
  int (*foo[10])(int) = {putchar};

  typedef int fun(int);
  typedef fun *fun_ptr;
  typedef fun_ptr fun_ptr_array[10];

  fun_ptr_array list;
  for (int i = 0; i < 10; i++) {
    list[i] = foo[i];
    printf("%p\n", list[i]);
  }

  return 0;
}