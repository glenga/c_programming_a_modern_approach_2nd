#include <stdio.h>

int main(void) {
  int days, start;

  printf("Enter number of days in month: ");
  scanf("%d", &days);

  printf("Enter starting day of the week (1=Sun, 7= sat): ");
  scanf("%d", &start);

  for (int i = 1; i < start; i++) {
    printf("    ");
  }

  for (int i = 1; i <= days; i++) {
    printf("%4d", i);

    // 判断星期6 换行
    if ((start + i - 1) % 7 == 0)
      printf("\n");
  }

  return 0;
}

// Enter number of days in month: 31
// Enter starting day of the week (1=Sun, 7= sat): 3