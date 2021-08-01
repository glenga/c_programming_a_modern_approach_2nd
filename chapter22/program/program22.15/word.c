#include "word.h"
#include <stdio.h>

// 这是一个不想公开的内部函数，不能放到头文件中
static int read_char(FILE *fp) {
  int ch = getc(fp);
  return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

// 读取一个单词
int read_word(char *word, int len, FILE *fp) {
  int ch, pos = 0;

  while ((ch = getc(fp)) == ' ')
    ;

  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = ch;
    ch = read_char(fp);
  }

  word[pos] = '\0';
  return pos;
}
