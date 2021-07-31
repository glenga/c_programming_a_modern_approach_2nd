#include <stdio.h>

int main(void) {
  int height = 8, length = 12, width = 10, volume;

  // height = 8;
  // length = 12;
  // width = 10;
  volume = height * length * width;

  // 向上取整方案 =>加上一个仅小于被除数的整数
  // weight = (volume + 165) / 166;

  printf("Dimensions: %dx%dx%d\n", length, width, height);
  printf("Volume (cubic inches): %d\n", volume);
  printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);

  return 0;
}