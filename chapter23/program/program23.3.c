#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 512

int read_line(char str[], int n, FILE *fp);
char buf[LINE_LEN + 1];

int main(int argc, char *argv[]) {
  if (2 != argc) {
    fprintf(stderr, "USAGE: %s filename.\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  // 将文件附加到stdin
  if ((fp = freopen(argv[1], "r", stdin)) == NULL) {
    fprintf(stderr, "open file  error: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while (!feof(stdin)) {
    if ((read_line(buf, LINE_LEN, stdin)) != 0) {
      buf[0] = toupper(buf[0]);
      fputs(buf, stdout);
      fputc('\n', stdout);
    }
  }

  fclose(fp);
  return 0;
}

int read_line(char str[], int n, FILE *fp) {
  int ch, i = 0;

  while (isspace(ch = getc(fp)))
    ;

  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;

    ch = getc(fp);
  }

  str[i] = '\0';

  return i;
}

// test: .\program23.3.exe text