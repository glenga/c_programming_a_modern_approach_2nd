#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define RANG_INT(a, b) (rand() % (b - a) + a)

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

//        4
//      3 A 1
//        2
//

int main() {
  int row, col;
  // 初始化
  char array[ROWS][COLS];
  for (row = 0; row < ROWS; row++) {
    for (col = 0; col < COLS; col++) {
      array[row][col] = '.';
    }
  }

  generate_random_walk(array);
  print_array(array);

  return 0;
}

// 随机移动
void generate_random_walk(char walk[10][10]) {
  int row = 0, col = 0, n;
  char flag = 'A';
  walk[row][col] = flag;

  bool blank = false;

  // 随机数
  srand((unsigned)time(NULL));

  while (!blank && flag < 'Z') {
    // 判断前后左右有没有空位
    if (col + 1 < COLS && walk[row][col + 1] == '.')
      blank = true;
    else if (row + 1 < ROWS && walk[row + 1][col] == '.')
      blank = true;
    else if (col - 1 >= 0 && walk[row][col - 1] == '.')
      blank = true;
    else if (row - 1 >= 0 && walk[row - 1][col] == '.')
      blank = true;
    else
      break;

    // 随机数
    n = RANG_INT(1, 5);

    switch (n) {
    case 1:
      if (col + 1 < COLS && walk[row][col + 1] == '.') {
        col += 1;
        walk[row][col] = ++flag;
      }
      break;
    case 2:
      if (row + 1 < ROWS && walk[row + 1][col] == '.') {
        row += 1;
        walk[row][col] = ++flag;
      }
      break;
    case 3:
      if (col - 1 >= 0 && walk[row][col - 1] == '.') {
        col -= 1;
        walk[row][col] = ++flag;
      }
      break;
    case 4:
      if (row - 1 >= 0 && walk[row - 1][col] == '.') {
        row -= 1;
        walk[row][col] = ++flag;
      }
      break;
    default:
      break;
    }
    // 下次循环默认上下左右没空位
    blank = false;
  }
}

// 打印数组
void print_array(char walk[10][10]) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      printf("%3c", walk[row][col]);
    }
    printf("\n");
  }
}
