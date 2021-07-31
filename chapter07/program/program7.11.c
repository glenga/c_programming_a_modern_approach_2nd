#include <ctype.h>
#include <stdio.h>

int main() {
  char surname, ch;
  printf("Enter a first and last name: ");

  // 跳过名字前的空白
  while ((ch = getchar()) == ' ')
    ;

  //得到名字的第一个字符(前面循环ch已经读取到了一个非空字符)
  surname = toupper(ch);

  // 跳过名字的其他字符 
  while ((ch = getchar()) != ' ')
    ;

  // 跳过姓前的空白 (前面循环ch已经读取到了一个空字符)
  while ((ch = getchar()) == ' ')
    ;

  // 输出名字 (前面循环ch已经读取到了一个非空字符)
  do {
    if (ch != ' ')
      putchar(ch);
  } while ((ch = getchar()) != '\n');

  printf(", %c.\n", surname);
  return 0;
}


// test:   Lloyd   Fosdick