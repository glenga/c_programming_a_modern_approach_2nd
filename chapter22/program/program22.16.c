#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  FILE *source_fp, *dest_fp;
  int buff[BUFSIZ], amount;

  if (3 != argc) {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }

  // 已二进制方式打开能够拷贝任何文件
  if (NULL == (source_fp = fopen(argv[1], "rb"))) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if (NULL == (dest_fp = fopen(argv[2], "wb"))) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(source_fp);
    exit(EXIT_FAILURE);
  }

  while ((amount = fread(buff, sizeof(char), BUFSIZ, source_fp)) != 0) {
    fwrite(buff, sizeof(char), amount, dest_fp);
  }

  fclose(source_fp);
  fclose(dest_fp);

  return 0;
}

// test: .\program22.16.exe .\message.txt .\message.txt.bak