#include <conio.h> // for getch() only windows
#include <stdio.h>

int main(void) {
  int i = 1, n;
  printf("Enter the integer n: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    printf("%d\t%d\n", i, i * i);

    if (i % 24 == 0) {
      printf("Press Enter to continue...\n");
      while (getch() == '\n')
        ;
    }
  }

  return 0;
}