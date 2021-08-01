#include <stdio.h>

int check(int x, int y, int n);

int main() {
  int x, y, n;
  printf("Enter the x y z: ");
  scanf("%d%d%d", &x, &y, &n);

  printf("The check result: %d\n", check(x, y, n));

  return 0;
}

int check(int x, int y, int n) {
  if (x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1)
    return 1;
  else
    return 0;
}