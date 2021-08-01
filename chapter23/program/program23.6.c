#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 512

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

  int line_len;
  while (fgets(buf, LINE_LEN, stdin)) {
    line_len = strlen(buf);
    while (line_len - 1 >= 0) {
      if (buf[line_len - 1] != '\n')
        buf[line_len - 1] = '?';

      line_len--;
    }

    if (ferror(stdout)) {
      fprintf(stderr, "input error\n");
      exit(EXIT_FAILURE);
    }

    puts(buf);
  }

  fclose(fp);
  return 0;
}

// .\program23.6.exe text