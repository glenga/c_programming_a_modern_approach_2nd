#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  char ch;
  bool start_with = false, end_with = false;
  int count = 0;

  while ((ch = getchar()) != EOF) {
    if (strchr(".,?!", ch)) {
      start_with = true;
      if (isspace(ch = getchar()))
        end_with = true;
      else if (strchr(".,?!", ch))
        start_with = true;
    } else {
      start_with = false;
      end_with = false;
    }

    if ((start_with && end_with) || (start_with && ch == EOF))
      count++;

    if (ch == EOF)
      break;
  }

  printf("sentence: %d\n", count);

  fclose(fp);
  return 0;
}

//  .\program23.7.exe text