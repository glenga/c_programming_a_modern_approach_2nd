#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 255

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

#define PART_SIZE sizeof(struct part)

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "usage: program22.9 src1.dat src2.dat dest.dat\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp_src1 = NULL, *fp_src2 = NULL, *fp_dest = NULL;

  if (NULL == (fp_src1 = fopen(argv[1], "rb"))) {
    fprintf(stderr, "error open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if (NULL == (fp_src1 = fopen(argv[2], "rb"))) {
    fprintf(stderr, "error open file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  if (NULL == (fp_src1 = fopen(argv[3], "wb"))) {
    fprintf(stderr, "error open file %s\n", argv[3]);
    exit(EXIT_FAILURE);
  }

  struct part part_src1, part_src2;

  // 每次读一个元素
  int count1 = fread(&part_src1, PART_SIZE, 1, fp_src1);
  int count2 = fread(&part_src2, PART_SIZE, 1, fp_src2);

  while (count1 == 1 && count2 == 1) {
    if (part_src1.number < part_src2.number) {
      fwrite(&part_src1, PART_SIZE, 1, fp_dest);
      count1 = fread(&part_src1, PART_SIZE, 1, fp_src1);
    } else if (part_src1.number > part_src2.number) {
      fwrite(&part_src2, PART_SIZE, 1, fp_dest);
      count2 = fread(&part_src2, PART_SIZE, 1, fp_src2);
    } else if (part_src1.number == part_src2.number) {
      // 文件名一致性比较
      if (strcmp(part_src1.name, part_src2.name) != 0) {
        fprintf(stderr,
                "error names math for part %d, "
                "source1 name: %s, source2 name: %s\n",
                part_src1.number, part_src1.name, part_src2.name);
      }
      //合并
      part_src1.on_hand += part_src2.on_hand;
      fwrite(&part_src1, PART_SIZE, 1, fp_dest);
      count1 = fread(&part_src1, PART_SIZE, 1, fp_src1);
      count2 = fread(&part_src2, PART_SIZE, 1, fp_src2);
    }
  }

  while (count1 == 1) {
    fwrite(&part_src1, PART_SIZE, 1, fp_dest);
    count1 = fread(&part_src1, PART_SIZE, 1, fp_src1);
  }

  while (count2 == 1) {
    fwrite(&part_src2, PART_SIZE, 1, fp_dest);
    count2 = fread(&part_src2, PART_SIZE, 1, fp_src2);
  }

  fclose(fp_src1);
  fclose(fp_src2);
  fclose(fp_dest);

  return 0;
}