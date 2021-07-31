#include <stdio.h>

int main(void) {
  int height, length, width, volume, weight;

  printf("Enter height of box: ");
  scanf("%d", &height);
  printf("Enter length of box: ");
  scanf("%d", &length);
  printf("Enter width of box: ");
  scanf("%d", &width);

  volume = height * length * width;
  weight = (volume + 165) / 166; // 向上取整方案 => 加上一个仅小于被除数的整数

  // printf("Dimensions: %dx%dx%d\n", length, width, height);
  printf("Volume (cubic inches): %d\n", volume);
  printf("Dimensional weight (pounds): %d\n", weight);

  return 0;
}

// Enter height of box: 8
// Enter length of box: 12
// Enter width of box: 10