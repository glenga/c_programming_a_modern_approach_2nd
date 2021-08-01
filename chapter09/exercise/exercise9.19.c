#include <stdio.h>

void pb(int n);

int main() {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);
  pb(n);

  return 0;
}

// 将整数转换成二进制显示
void pb(int n) {
  if (n != 0) {
    pb(n / 2);
    putchar('0' + n % 2);
  }
}