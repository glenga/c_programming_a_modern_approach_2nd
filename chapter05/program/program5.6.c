#include <stdio.h>

int main(void) {

  int array[12];

  printf("Enter a complete UPC: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &array[0], &array[1], &array[2],
        &array[3], &array[4], &array[5], &array[6], &array[7], &array[8],
        &array[9], &array[10], &array[11]);

  int sum1 = 0, sum2 = 0;
  // 奇数位
  for (int i = 0; i < 11; i += 2)
    sum1 += array[i];

  // 偶数位
  for (int i = 1; i < 11; i += 2)
    sum2 += array[i];

  int check_sum = 9 - (sum1 * 3 + sum2 - 1) % 10;

  if (array[11] == check_sum)
    printf("VALID\n");
  else
    printf("NOT VALID\n");

  return 0;
}

// Enter a complete UPC: 01380015173
// Enter a complete UPC: 869148426000