#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ROW_COUNT 16

int main(int argc, char *argv[]) {
  // 只能是unsigned char 类型, char 类型会有奇怪显示错误
  unsigned char buff[ROW_COUNT + 1];
  int i, offset = 0, ch_count = 0;

  if (2 != argc) {
    fprintf(stderr, "parameter error!\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "rb");
  if (NULL == fp) {
    fprintf(stderr, "error open file: %s\n", argv[1]);
  }

  printf("\n");
  printf("offset    "
         "                       Bytes                            "
         "   characters   \n");
  printf("--------    "
         "-----------------------------------------------     "
         "----------------\n");

  do {
    ch_count = fread(buff, sizeof(char), ROW_COUNT, fp);
    if (ch_count) {
      buff[ch_count] = '\0';
      // offset 列
      printf("%08X    ", offset);
      // bytes 列
      for (i = 0; i < ROW_COUNT && i < ch_count; i++) {
        printf("%.2X ", buff[i]);

        if (!isprint(buff[i]))
          buff[i] = '.';
      }
      // 不够一列补全
      for (; i < ROW_COUNT; i++)
        printf("   ");

      printf("    ");

      // characters 列
      printf("%s\n", buff);

      offset += ROW_COUNT;
    }
  } while (ch_count);

  fclose(fp);

  return 0;
}

// test: .\program22.6.exe .\program22.6.c