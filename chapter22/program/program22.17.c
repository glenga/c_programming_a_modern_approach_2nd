#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int read_line(char str[], int n, FILE *fp);

int main(int argc, char *argv[]) {
  if (2 != argc) {
    fprintf(stderr, "Error: missing file name.\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;

  if (NULL == (fp = fopen(argv[1], "r"))) {
    fprintf(stderr, "error open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  char line[255];

  int area, local, exact;

  while (read_line(line, 255, fp) != 0) {
    sscanf(line,
           line[0] == '(' ? "%*[(]%3d%*[)]%3d%*[. -]%4d"
                          : "%3d%*[. -]%3d%*[. -]%4d",
           &area, &local, &exact);
    printf("(%.3d) %.3d-%.4d\n", area, local, exact);
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

// test: .\program22.17.exe .\tel.txt