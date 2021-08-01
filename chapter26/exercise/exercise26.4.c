#include <stdarg.h>
#include <stdio.h>

void display(int n, char *s, ...);

int main() {

  display(4, "Special", "Agent", "Dale", "Cooper");

  return 0;
}

void display(int n, char *s, ...) {
  char *str;

  printf("%s ", s);

  va_list ap;
  va_start(ap, s); // ap 从 start 的下一个元素开始
  while (n > 1) {
    str = va_arg(ap, char *);
    printf("%s ", str);
    n--;
  }

  va_end(ap);

  printf("\n");
}
