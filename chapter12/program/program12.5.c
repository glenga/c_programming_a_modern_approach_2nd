#include <stdbool.h>
#include <stdio.h>

// 反向输出一个句子
int main() {
  char sentence[100];
  char ch;

  char *current = sentence, *end;

  printf("Enter a sentence: ");

  while ((ch = getchar()) != '\n') {
    if (ch == '!' || ch == '.' || ch == '?')
      break;

    *current++ = ch;
  } // 此时 index 在标点符号的位置上

  // 反向输出
  printf("Reversal of sentences: ");

  while (current >= sentence) {
    end = current;
    // 1. 寻找单词起点
    while (current >= sentence && *current != ' ')
      current--; // 此时sentence[index]为单词前的空格 或者-1

    // 2. 输出单词
    for (char *start = current + 1; start <= end; start++)
      printf("%c", *start);

    // 3. 计算空白字符,原样输出
    while (current >= sentence && *current == ' ') {
      printf(" ");
      current--;
    }
  }

  printf("%c\n", ch);
  return 0;
}

// test:  you can  cage  a swallow can't   you?