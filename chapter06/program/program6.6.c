#include <stdio.h>

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  for (int i = 1; i * i <= n; i++) {

    if (i % 2 == 0)
      printf("%d\n", i * i);
  }

  return 0;
}

// Enter a number: 100