#include <stdio.h>

void (*foo_x(int, void (*foo_y)(int)))(int); // 声明

void foo_y(int b) { printf("In foo_y: %d\n", b); }
void return_func(int c) { printf("In return_func: %d\n", c); }

int main() {
  typedef void func_y(int);
  typedef func_y *fn_ptr_y;

  typedef void func_x(int);
  typedef func_x *fn_ptr_x;
  typedef fn_ptr_x fx(int, fn_ptr_y);

  //先来个自动类型的
  __auto_type ret_fn = foo_x(10, foo_y);
  ret_fn(30);

  // 再看看定义的类型别名对不对
  fx *f = foo_x;
  ret_fn = (*f)(40, foo_y);
  ret_fn(50);

  return 0;
}

void (*foo_x(int a, void (*foo_y)(int b)))(int c) { //定义
  printf("In foo_x: %d\n", a);
  (*foo_y)(20);
  return return_func;
}