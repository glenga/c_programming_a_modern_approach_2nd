#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int get_word_count(FILE *fp);

int main(int argc, char *argv[]) {
  int word_count = 0;

  if (argc != 2) {
    fprintf(stderr, "parameter error!\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");
  if (NULL == fp) {
    fprintf(stderr, "error open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  word_count = get_word_count(fp);

  fclose(fp);

  printf("number of words: %d\n", word_count);
}

int get_word_count(FILE *fp) {
  int ch, word_count = 0;

  while (true) {
    while (' ' == (ch = getc(fp)))
      ;
    if (ch == EOF)
      break;

    while (' ' != (ch = getc(fp))) {
      if (ch == EOF)
        break;
    }
    word_count++;

    if (ch == EOF)
      break;
  }

  return word_count;
}

// test: .\program22.4b.exe  msg