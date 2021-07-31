#include <stdio.h>

int main(void) {
  int num1, denom1, num2, denom2, result_num = 0, result_denom = 0;
  char symbol;
  printf("enter two scores for calculation (eg: 1/3 * 3/5): ");
  scanf("%d /%d %c%d /%d", &num1, &denom1, &symbol, &num2, &denom2);

  if (symbol == '+') {
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
  } else if (symbol == '-') {
    result_num = num1 * denom2 - num2 * denom1;
    result_denom = denom1 * denom2;
  } else if (symbol == '*') {
    result_num = num1 * num2;
    result_denom = denom1 * denom2;
  } else if (symbol == '/') {
    result_num = num1 * denom2;
    result_denom = denom1 * num2;
  } else
    printf("Operator Error!\n");

  printf("The sum is: %d/%d\n", result_num, result_denom);

  return 0;
}

// enter two scores for calculation (eg: 1/3 * 3/5): 1/3 *3/5