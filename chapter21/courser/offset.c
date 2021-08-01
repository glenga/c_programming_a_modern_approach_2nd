#include <stdbool.h> // C99+ 布尔类型定义
#include <stddef.h> // 提供了常用类型和宏的定义,但没有声明任何函数。 offsetof
#include <stdio.h>
#include <ctype.h>


struct s {
  char a;
  int b[20];
  float c;
};

int main() {
  struct s st_s = {'X', {[2] = 0}, 10.0};

  printf("c: %.1f, offsetof struct: %I64u\n", st_s.c, offsetof(struct s, c));

  return 0;
}