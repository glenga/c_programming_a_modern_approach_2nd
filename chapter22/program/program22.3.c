#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "USAGE: %s filename filename2 ...\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  char ch;

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      fprintf(stderr, "Error: file %s cannot be opened\n", argv[i]);
      exit(EXIT_FAILURE);
    } else {
      while ((ch = getc(fp)) != EOF)
        putchar(ch);
      fclose(fp);
    }
  }

  return 0;
}