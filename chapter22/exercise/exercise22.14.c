#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

char *my_fgets(char *s, int n, FILE *stream);
int my_fputs(const char *s, FILE *stream);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "parameter error!\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");
  if (NULL == fp) {
    fprintf(stderr, "error open file %s", argv[1]);
    exit(EXIT_FAILURE);
  }

  char buff[MAX_LEN];
  my_fputs(my_fgets(buff, MAX_LEN, fp), stdout);

  return 0;
}

char *my_fgets(char *s, int n, FILE *stream) {
  int ch, len = 0;
  while (len < n - 1) {
    if ((ch = getc(stream)) == EOF) {
      if (len == 0 || ferror(stream))
        return NULL;

      break;
    }

    s[len++] = ch;
    if (ch == '\n')
      break;
  }
  s[len] = '\0';
  return s;
}

int my_fputs(const char *s, FILE *stream) {
  while (*s != '\0') {
    if (putc(*s, stream) == EOF)
      return EOF;

    s++;
  }
  return 0;
}

// test: exercise22.14.exe .\exercise22.14.c