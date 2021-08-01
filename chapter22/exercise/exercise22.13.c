#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n);

int main(int argc, char *argv[]) {
  int n;
  if (argc != 2) {
    fprintf(stderr, "parameter error!\n");
    exit(EXIT_FAILURE);
  }

  printf("Enter the line: ");
  scanf("%d", &n);

  printf("line %d length: %d\n", n, line_length(argv[1], n));

  return 0;
}

int line_length(const char *filename, int n) {
  FILE *fp = NULL;
  int ch, len = 0;

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "error open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  while (n > 1) {
    // 跳过n-1行
    while ((ch = fgetc(fp)) != '\n') {
      if (ch == EOF)
        return len;
    }
    n--;
  }
  //第n行
  while ((ch = fgetc(fp)) != '\n' && ch != EOF)
    len++;
  return len;
}

// exercise22.13.exe .\exercise22.13.c
// Enter the line: 32
// line 32 length: 38