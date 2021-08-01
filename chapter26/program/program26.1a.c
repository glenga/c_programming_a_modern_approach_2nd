#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 1000

int main() {
  int digit_count[10] = {0}; // 使用一个数组统计一下每个数次出现的次数

  srand(time(NULL));
  int digit;
  for (int i = 0; i < COUNT; i++) {
    digit = rand();
    while (digit >= 10)
      digit %= 10;

    digit_count[digit]++;

    // printf("%d\n", digit);
  }

  for (int i = 0; i < 10; i++) {
    printf("数字 %d 出现的机率: %.2f%%\n", i,
           (double)(digit_count[i] * 100) / COUNT);
  }
}