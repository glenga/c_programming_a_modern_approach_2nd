#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

void my_printf(char *s, ...);

int main() {
  int a = 100000, b = -1000, c = 10230,
      d = 9876;
  const char *s = "hello,world!";

  my_printf("%%%d % %s %d %d %d\n", a, s, b, c, d);

  return 0;
}

void my_printf(char *s, ...) {
  va_list ap;
  bool percent = false;
  int digit, i, power, temp;
  char *p;

  va_start(ap, s);

  while (*s) {
    if (percent) {
      if (*s == 'd') {
        i = va_arg(ap, int);
        if (i < 0) {
          i = -i;
          putchar('-');
        }
        temp = i;
        power = 0; // 10 的幂
        while (temp > 9) {
          temp /= 10;
          power++;
        }

        while (power >= 0) {
          int t = power, divisor = 1;
          while (t > 0) {
            divisor = divisor * 10;
            t--;
          }

          digit = i / divisor;
          putchar(digit + '0');
          i = i - (digit * divisor);

          power--;
        }
        // 下一个占位符
        s++;
      } else if (*s == 's') {
        p = va_arg(ap, char *);
        while (*p) {
          putchar(*p);
          p++;
        }
        // 下一个占位符
        s++;
      }

      // 没有获取到格式化占位符就忽略
      percent = false;
    }

    if (*s == '%')
      percent = true;
    else
      putchar(*s); // 格式化字符串中的空格

    s++;
  }
  va_end(ap);
}