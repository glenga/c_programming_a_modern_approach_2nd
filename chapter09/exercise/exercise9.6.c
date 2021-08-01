#include <stdio.h>

int digit(int number, int pos);

int main() {
  int number, pos;
  printf("Enter a number and pos: ");
  scanf("%d%d", &number, &pos);
  printf("The digit is %d.\n", digit(number, pos));
  return 0;
}

int digit(int number, int pos) {
  int count = 1, digit;
  do {
    digit = number % 10;
    number /= 10;
    count++;
  } while (number > 0 && count <= pos);

  return digit;
}