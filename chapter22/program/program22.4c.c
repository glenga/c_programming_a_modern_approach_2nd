#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 512

int get_line_count(FILE *fp);

int main(int argc, char *argv[]) {
  int line_count = 0;

  if (argc != 2) {
    fprintf(stderr, "parameter error!\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");
  if (NULL == fp) {
    fprintf(stderr, "error open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  line_count = get_line_count(fp);

  fprintf(stderr, "lines of text: %d\n", line_count);

  fclose(fp);

  return 0;
}

int get_line_count(FILE *fp) {
  int line_count = 1, ch;
  while ((ch = getc(fp)) != EOF) {
    if (ch == '\n') {
      line_count++;
      continue;
    }
  }
  return line_count;
}

// test: .\program22.4c.exe  .\program22.4c.c