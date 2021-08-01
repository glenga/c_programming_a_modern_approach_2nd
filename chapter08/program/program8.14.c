#include <stdbool.h>
#include <stdio.h>

// 反向输出一个句子
int main() {
  char sentence[100];
  char ch;
  int index = 0, end;

  printf("Enter a sentence: ");

  while ((ch = getchar()) != '\n') {
    if (ch == '!' || ch == '.' || ch == '?')
      break;

    sentence[index++] = ch;
  } // 此时 index 在标点符号的位置上

  // 反向输出
  printf("Reversal of sentences: ");

  while (index >= 0) {
    end = index;
    // 1. 寻找单词起点
    while (index >= 0 && sentence[index] != ' ')
      index--; // 此时sentence[index]为单词前的空格 或者-1

    // 2. 输出单词
    for (int start = index + 1; start <= end; start++)
      printf("%c", sentence[start]);

    // 3. 计算空白字符,原样输出
    while (index >= 0 && sentence[index] == ' ') {
      printf(" ");
      index--;
    }
  }

  printf("%c\n", ch);
  return 0;
}

// test:  you can  cage  a swallow can't   you?