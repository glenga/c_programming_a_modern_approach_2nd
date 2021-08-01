#include <locale.h>
#include <stdio.h>

int main() {
  char *locale, *back_locale;
  // 获取当前模式, 默认为"C"
  locale = setlocale(LC_ALL, NULL);
  if (NULL == locale) {
    printf("Locale not set!\n");
    return 0;
  }

  printf("locale: %s\n", locale);

  back_locale = locale;
  // 设置为本地模式
  locale = setlocale(LC_ALL, "");

  printf("locale: %s\n", locale);

  // 还原默认locale设置
  locale = setlocale(LC_ALL, back_locale);
  printf("locale: %s\n", locale);
}