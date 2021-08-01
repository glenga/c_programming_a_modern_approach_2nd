#include <stdio.h>
#include <stdlib.h>

// 函数返回函数指针
float *(*foo(void))(int); // 声明

float f;

float *change_to_float_ptr(int n) {
  f = (float)n;
  return &f;
}

int main() {
  typedef float *fun(int);
  typedef fun *fun_ptr;
  typedef fun_ptr fn_x(void);

  fn_x *f = foo;

  // 为了验证写法正确而写的无意义代码, 九拐十八弯
  // 这里用一个gcc的变量自动类型扩展.
  __auto_type fn_ptr = f();
  float *pf = (*fn_ptr)(1000);

  printf("%p======>%.2f\n", pf, *pf);
  return 0;
}

float *(*foo(void))(int) { // 定义
  return change_to_float_ptr;
}