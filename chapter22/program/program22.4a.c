#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int ch, ch_count = 0;

  if (argc != 2) {
    fprintf(stderr, "parameter error!\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");
  if (NULL == fp) {
    fprintf(stderr, "error open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while (EOF != (ch = getc(fp))) {
    if (isprint(ch)) // 可见字符
      ch_count++;
  }

  fclose(fp);

  printf("number of characters: %d\n", ch_count);
}

// test:  .\program22.4a.exe .\program22.4a.c