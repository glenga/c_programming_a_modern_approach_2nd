#include <ctype.h>
#include <stdio.h>

int main() {
  float RSH, sum;
  char op;

  printf("Enter an expression: ");
  // 读取第一个操作数
  scanf("%f", &sum);

  while ((op = getchar()) != '\n') {
    // 跳过操作符前面的空白, 知道op读到需要的操作符
    if (op == ' ')
      continue;

    scanf("%f", &RSH);

    switch (op) {
    case '+':
      sum += RSH;
      break;
    case '-':
      sum -= RSH;
      break;
    case '*':
      sum *= RSH;
      break;
    case '/':
      sum /= RSH;
      break;
    }
  }

  printf("Value of expression: %.2f", sum);
  return 0;
}

// Enter an expression: 1+2.5*3