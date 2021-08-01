#include <stdio.h>
#include <stdlib.h>

void f1(void);
void f2(void);

int main() {
  atexit(f2);
  atexit(f1); // 最后注册的函数最先调用,栈模式

  return 0;
}

void f1(void) { printf("That's all, "); }

void f2(void) { printf("Folks!\n"); }