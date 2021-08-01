#include <assert.h>
#include <stdio.h>

// 奇数阶幻方
int main() {
  int size;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &size);
  // 必须奇数
  assert(size % 2 == 1);

  // 变长数组,不能初始化
  //   int array[size][size] = {0};
  int array[size][size];

  // 初始化
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      array[i][j] = 0;
    }
  }

  int row = 0, col = size / 2, count = 1;
  // 开始位置,第一行中间
  array[row][col] = count;

  for (int i = 1; i < size * size; i++) {
    // 存右上角
    if (array[(row + size - 1) % size][(col + 1) % size] == 0) {
      row = (row + size - 1) % size;
      col = (col + 1) % size;
    } else { // 右上角占用存正下方
      row = (row + 1) % size;
    }

    array[row][col] = ++count;
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%4d", array[i][j]);
    }
    printf("\n");
  }

  return 0;
}