#include <ctype.h>
#include <stdio.h>

#define STR_LEN 80

void reverse_name(char *name);

int main() {
  char name[STR_LEN + 1];

  printf("Enter a first and last name: ");
  fgets(name, sizeof(name), stdin);
  reverse_name(name);

  return 0;
}

void reverse_name(char *name) {
  char surname;

  // 跳过名字前的空白
  while (*name == ' ')
    name++;
  //得到名字的第一个字符(前面循环ch已经读取到了一个非空字符)
  surname = toupper(*name);

  // 跳过名字的其他字符
  while (*name != ' ')
    name++;

  // 跳过姓前的空白 (前面循环ch已经读取到了一个空字符)
  while (*name == ' ')
    name++;

  do {
    putchar(*name++);

  } while (*name != '\n');

  printf(", %c.\n", surname);
}

// test:       Lloyd     Fosdick