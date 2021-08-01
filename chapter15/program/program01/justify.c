#include "line.h"
#include "word.h"
#include <string.h>

#define MAX_WORD_LEN 20

int main(void) {

  char word[MAX_WORD_LEN + 2];
  int word_len;

  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN + 1);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    // if (word_len > MAX_WORD_LEN)
    //   word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
  }

  return 0;
}

//  gcc -o justify.exe justify.c line.c word.c
// justify.exe <quoite 
// window10 只能在cmd命令提示符下运行,powershell7不支持输出重定向。
