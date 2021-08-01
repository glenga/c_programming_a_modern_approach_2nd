
#include <stdio.h>
//                   0
//                   -        -
//                 5|6|1     | |
//                   -        -
//                 4|3|2     | |
//                   -        -
//   // 7 段显示器
int main() {

  const int segments[10][7] = {{1, 1, 1, 1, 1, 1},    {0, 1, 1},
                               {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
                               {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
                               {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

  int x;
  printf("输入一个数字(ctr+c退出): ");
  while (scanf("%1d", &x) != EOF) {
    if (segments[x][0])
      printf(" - \n");
    else
      printf("   \n");

    if (segments[x][5])
      printf("| ");
    else
      printf("  ");

    if (segments[x][1])
      printf("|\n");
    else
      printf(" \n");

    if (segments[x][6])
      printf(" - \n");
    else
      printf("   \n");

    if (segments[x][4])
      printf("| ");
    else
      printf("  ");

    if (segments[x][2])
      printf("|\n");
    else
      printf(" \n");

    if (segments[x][3])
      printf(" - \n");
    else
      printf("   \n");

    printf("输入一个数字(ctr+c退出): ");
  }

  return 0;
}