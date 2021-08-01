#include <ctype.h>
#include <stdio.h>

int main() {
  char surname, name[20], ch;
  int n = 0;
  printf("Enter a first and last name: ");

  // 跳过名字前的空白
  while ((ch = getchar()) == ' ')
    ;

  //得到姓氏的第一个字符(前面循环ch已经读取到了一个非空字符)
  surname = toupper(ch);

  // 跳过姓氏的其他字符
  while ((ch = getchar()) != ' ')
    ;

  // 跳过名字前的空白 (前面循环ch已经读取到了一个空字符)
  while ((ch = getchar()) == ' ')
    ;

  // 输出名字 (前面循环ch已经读取到了一个非空字符)
  do {
    if (ch != ' ')
      //   putchar(ch);
      name[n++] = ch;

  } while ((ch = getchar()) != '\n');

  printf("You enered the name: ");
  for (int i = 0; i < n; i++)
    printf("%c", name[i]);

  printf(", %c.", surname);

  return 0;
}

// Lloyd Fosdick