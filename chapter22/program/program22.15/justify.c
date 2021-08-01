#include "line.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int main(int argc, char *argv[]) {
  FILE *src_fp, *des_fp;
  char word[MAX_WORD_LEN + 2];
  int word_len;

  if (argc != 3) {
    fprintf(stderr, "USAGE: %s input-file output-file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((src_fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Error: file %s cannot be read\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((des_fp = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Error: file %s cannot be written\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN + 1, src_fp);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line(des_fp);
      break;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line(des_fp);
      clear_line();
    }
    add_word(word);
  }

  fclose(src_fp);
  fclose(des_fp);

  exit(EXIT_SUCCESS);
}

//  gcc -o justify.exe justify.c line.c word.c
// justify.exe quote new_quote
