#include <stdio.h>

int f(char *s, char *t);

int main() {
  char *str1 = "abcd";

  char *str2 = "babc";
  // char *str2 = "bcd";

  printf("%d\n", f(str1, str2));

  return 0;
}

int f(char *s, char *t) {
  char *p1, *p2;

  // 在t串中搜索s串
  for (p1 = s; *p1; p1++) {
    for (p2 = t; *p2; p2++) {
      if (*p1 == *p2)
        break;
    }

    if (*p2 == '\0')
      break;
  }

  return p1 - s; // s串中的偏移量
}