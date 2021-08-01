#include <ctype.h>
#include <stdio.h>

#define LEN_STR 50

int read_line(char str[], int n);

int main() {
  char str[LEN_STR + 1];

  printf("Enter string: ");

  read_line(str, LEN_STR);

  printf("%s", str);

  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;

  while (isspace(ch = getchar())) // a 跳过空白字符
    ;

  while (ch) {
    if (ch == '\n' || isspace(ch)) // b d
      break;

    if (i > n - 1) // c
      break;

    str[i++] = ch;
    ch = getchar();
  }

  str[i] = '\0';
  return i;
}

// test:    China is great, I love china!