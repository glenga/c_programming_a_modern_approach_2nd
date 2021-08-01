#include "line.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 60

char line_buff[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;
bool more_space_toggle = false;

// 清空行缓冲区
void clear_line(void) {

  line_buff[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word) {

  // 每个单词后面加一个空格,并将单词用字符串表示
  if (num_words > 0) {
    line_buff[line_len] = ' ';
    line_buff[line_len + 1] = '\0';
    line_len++;
  }
  strcat(line_buff, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

void write_line(void) {

  int extra_spaces, spaces_to_insert;
  more_space_toggle = !more_space_toggle;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (int i = 0; i < line_len; i++) {
    if (line_buff[i] != ' ')
      putchar(line_buff[i]);
    else {
      spaces_to_insert = extra_spaces / (num_words - 1);
      if (more_space_toggle && extra_spaces > 0) {
        spaces_to_insert++;
        more_space_toggle = !more_space_toggle;
      }
      for (int j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line(void) {
  if (line_len > 0)
    puts(line_buff);
}