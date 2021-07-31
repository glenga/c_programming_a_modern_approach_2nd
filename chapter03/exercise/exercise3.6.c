#include <stdio.h>

int main(void) {
  int num1, denom1, num2, denom2, result_num, result_denom;

  printf("Enter first fraction: ");
  // 在/的前后都加上空格显然可以完成目标，但不是一个好方法,参见练习题3解释
  // scanf("%d / %d", &num1, &denom1);
  scanf("%d /%d", &num1, &denom1);

  printf("Enter second fraction: ");
  scanf("%d / %d", &num2, &denom2);

  result_num = num1 * denom2 + num2 * denom1;
  result_denom = denom1 * denom2;
  printf("The sum is %d/%d\n", result_num, result_denom);

  return 0;
}

// Enter first fraction: 5/6
// Enter second fraction: 3/4