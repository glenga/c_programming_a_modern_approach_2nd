#include "word.h"
#include <stdio.h>

// 这是一个不想公开的内部函数，不能放到头文件中
int read_char(void) {
  int ch = getchar();
  return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

// 读取一个单词
int read_word(char *word, int len) {
  int ch, pos = 0;

  while ((ch = getchar()) == ' ')
    ;

  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = ch;
    ch = read_char();
  }

  word[pos] = '\0';
  return pos;
}
