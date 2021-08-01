#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define RANG_INT(a, b) (rand() % (b - a) + a)

int main() {
  int row, col, direction;

  // 初始化
  char array[ROWS][COLS];
  for (row = 0; row < ROWS; row++) {
    for (col = 0; col < COLS; col++) {
      array[row][col] = '.';
    }
  }

  // 随机数
  srand((unsigned)time(NULL));
  char flag = 'A';
  row = 0, col = 0;
  array[row][col] = flag;

  bool have_blank = false;

  while (!have_blank && flag < 'Z') {
    // 判断前后左右有没有空位
    if (col + 1 < COLS && array[row][col + 1] == '.')
      have_blank = true;
    else if (row + 1 < ROWS && array[row + 1][col] == '.')
      have_blank = true;
    else if (col - 1 >= 0 && array[row][col - 1] == '.')
      have_blank = true;
    else if (row - 1 >= 0 && array[row - 1][col] == '.')
      have_blank = true;
    else
      break;

    // 定义方向
    //        4
    //      3 A 1
    //        2
    //
    direction = RANG_INT(1, 5);

    switch (direction) {
    case 1:
      if (col + 1 < COLS && array[row][col + 1] == '.')
        col += 1;
      break;
    case 2:
      if (row + 1 < ROWS && array[row + 1][col] == '.')
        row += 1;
      break;
    case 3:
      if (col - 1 >= 0 && array[row][col - 1] == '.')
        col -= 1;
      break;
    case 4:
      if (row - 1 >= 0 && array[row - 1][col] == '.')
        row -= 1;
      break;
    }

    // 避免原地填充
    if (array[row][col] == '.')
      array[row][col] = ++flag;

    // 下次循环重新检查
    have_blank = false;
  }

  // 打印数组
  for (row = 0; row < ROWS; row++) {
    for (col = 0; col < COLS; col++) {
      printf("%3c", array[row][col]);
    }
    printf("\n");
  }

  return 0;
}