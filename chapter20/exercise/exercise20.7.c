#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main() {
  unsigned int i;
  printf("Enter a hexadecimal number (up to four digits): ");
  scanf("%x", &i);
  printf("Number with bytes rotate left: %x\n", rotate_left(i, 4));
  printf("Number with bytes rotate left: %x\n", rotate_left(i, 8));
  printf("Number with bytes rotate left: %x\n", rotate_left(i, 16));
  printf("Number with bytes rotate left: %x\n", rotate_left(i, 32));

  printf("\n");

  printf("Number with bytes rotate right: %x\n", rotate_right(i, 4));
  printf("Number with bytes rotate right: %x\n", rotate_right(i, 8));
  printf("Number with bytes rotate right: %x\n", rotate_right(i, 16));
  printf("Number with bytes rotate right: %x\n", rotate_right(i, 32));
  return 0;
}

// 循环左移
unsigned int rotate_left(unsigned int i, int n) {
  return (i << n) | (i >> (sizeof(int) * 8 - n));
}

// 循环右移
unsigned int rotate_right(unsigned int i, int n) {
  return (i << (sizeof(int) * 8 - n)) | (i >> n);
}

// test: Enter a hexadecimal number (up to four digits): 12345678