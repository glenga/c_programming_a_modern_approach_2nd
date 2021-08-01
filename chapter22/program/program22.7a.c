#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress_file(FILE *src_fp, FILE *des_fp);

int main(int argc, char *argv[]) {
  if (2 != argc) {
    fprintf(stderr, "parameter error!\n");
    exit(EXIT_FAILURE);
  }

  FILE *src_fp, *des_fp;
  char out_file[strlen(argv[1] + 5)];

  if (NULL == (src_fp = fopen(argv[1], "rb"))) {
    fprintf(stderr, "error open file: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  } else {
    strcpy(out_file, argv[1]);
    strcat(out_file, ".rle");
    // printf("%s\n", out_file);
    if (NULL == (des_fp = fopen(out_file, "wb"))) {
      fprintf(stderr, "error create file: %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  }

  compress_file(src_fp, des_fp);

  fclose(src_fp);
  fclose(des_fp);

  return 0;
}

void compress_file(FILE *src_fp, FILE *des_fp) {
  unsigned char amount; // 只占用一个字节,不能大于0xFF
  char cur_byte, next_byte;
  long pos;

  while (fread(&cur_byte, sizeof(char), 1, src_fp) > 0) {
    amount = 1;
    pos = ftell(src_fp);
    while (fread(&next_byte, sizeof(char), 1, src_fp) > 0 &&
           next_byte == cur_byte) {
      amount++;
    }
    fwrite(&amount, sizeof(char), 1, des_fp);
    fwrite(&cur_byte, sizeof(char), 1, des_fp);
    fseek(src_fp, pos + (amount - 1), SEEK_SET);
  }
}

// test: .\program22.7a.exe msg
// test: .\program22.6.exe .\msg.rle
