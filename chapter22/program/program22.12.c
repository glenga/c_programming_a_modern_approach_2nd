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
  int item, month, day, year;
  double price;

  printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
  while (read_line(line, 255, fp) != 0) {
    sscanf(line, "%d,%lf,%d%*[/-]%d%*[/-]%d", &item, &price, &month, &day,
           &year);
    printf("%d\t\t$%8.2lf\t%.2d/%.2d/%.4d\n", item, price, month, day, year);
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

// test: .\program22.12.exe .\data.txt