#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "USEAGE: %s sourcefile destinationfile\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *src_fp, *des_fp;

  if (NULL == (src_fp = fopen(argv[1], "rb"))) {
    fprintf(stderr, "error open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if (NULL == (des_fp = fopen(argv[2], "wb"))) {
    fprintf(stderr, "error open file %s\n", argv[2]);
    fclose(src_fp);
    exit(EXIT_FAILURE);
  }

  int ch;
  while ((ch = getc(src_fp)) != EOF) {
    if (ch == '\x0a')
      fputc('\x0d', des_fp);

    fputc(ch, des_fp);
  }

  fclose(src_fp);
  fclose(des_fp);
  return 0;
}