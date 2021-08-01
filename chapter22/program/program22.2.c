#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int ch;

  if (2 != argc) {
    fprintf(stderr, "parameter error!\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp = NULL;

  if (NULL == (fp = fopen(argv[1], "r"))) {
    fprintf(stderr, "error open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(fp)) != EOF) {
    if (isalpha(ch))
      putchar(toupper(ch));
    else
      putchar(ch);
  }

  fclose(fp);

  return 0;
}

// test:  .\program22.2.exe program22.2.c