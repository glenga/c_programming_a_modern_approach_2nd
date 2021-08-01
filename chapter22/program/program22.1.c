#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;

  if (argc < 2) {
    printf("Usage: canopen filename!\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      printf("%s can't be opened!\n", argv[i]);
      exit(EXIT_FAILURE);
    } else {
      printf("%s can be opened!\n", argv[i]);
      fclose(fp);
      fp = NULL;
    }
  }
  return 0;
}

// test: .\program22.1.exe program22.1.c  foo bar baz