#include <stdio.h>

int main(void) {
  int n;

  printf("Enter the integer n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    printf("%d\t%d\n", i, i * i);

  printf("\n\n type int max value: %d\n", __INT_MAX__);
  printf("When The Input Integer Exceeds 46340 The Square Exceeds An Integer "
         "Range And The Result Will Exceed!!!\n");
  return 0;
}