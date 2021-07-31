#include <stdio.h>

int main() {
  long num;

  printf("Enter a num: ");
  scanf("%ld", &num);
  printf("this number of reverse sequence is: ");
  do {
    printf("%ld", num % 10);
    num /= 10;
  } while (num > 0);

  return 0;
}

// Enter a num: 100000