#include <assert.h>
#include <stdio.h>

// 可变数组
void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

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

  create_magic_square(size, array);

  print_magic_square(size, array);

  return 0;
}

// 创建幻方数组
void create_magic_square(int n, int magic_square[n][n]) {
  // 初始化
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      magic_square[i][j] = 0;
    }
  }

  int row = 0, col = n / 2, count = 1;
  // 开始位置,第一行中间
  magic_square[row][col] = count;

  for (int i = 1; i < n * n; i++) {
    // 存右上角
    if (magic_square[(row + n - 1) % n][(col + 1) % n] == 0) {
      row = (row + n - 1) % n;
      col = (col + 1) % n;
    } else { // 右上角占用存正下方
      row = (row + 1) % n;
    }

    magic_square[row][col] = ++count;
  }
}

// 显示
void print_magic_square(int n, int magic_square[n][n]) {
  int sum;
  for (int i = 0; i <= n; i++)
    printf("    ");

  printf("sum\n");

  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = 0; j < n; j++) {
      printf("%4d", magic_square[i][j]);
      sum += magic_square[i][j];
    }
    printf("%7d\n", sum);
  }
}

// Enter size of magic square: 5