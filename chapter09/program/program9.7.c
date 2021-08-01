
#include <stdio.h>

int power(int x, int y);

int main() {
  int x, n;
  printf("Enter the number x and n: ");
  scanf("%d%d", &x, &n);

  printf("the  power(x, n): %d\n", power(x, n));

  return 0;
}

int power(int x, int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return x;
  else if (n % 2 == 0) {
    int temp = power(x, n / 2);
    return temp * temp;
  } else {
    int temp = power(x, n / 2);
    return temp * temp * x;
  }
}

// Enter the number x and n: 6 6