#include <stdio.h>

int count_ones(unsigned char ch);

int main() {
  char ch;

  printf("Enter the char: ");
  scanf("%c", &ch);

  printf("字符 \'%c\' 的二进制形式包含 %d 个 1.\n", ch, count_ones(ch));

  return 0;
}

int count_ones(unsigned char ch) {
  if (ch == 0)
    return 0;
  return count_ones(ch & (ch - 1)) + 1;
}