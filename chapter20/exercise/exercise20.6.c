#include <stdio.h>

#define SWAP_BYTES(x) (((x) << 8) | ((x) >> 8))

unsigned short swap_bytes(unsigned short i);

int main() {
  unsigned short i;
  printf("Enter a hexadecimal number (up to four digits): ");
  scanf("%hx", &i);
  printf("Number with bytes swapped: %.4hx\n", swap_bytes(i));
  printf("Number with bytes swapped: %.4hx\n", SWAP_BYTES(i));
  return 0;
}

unsigned short swap_bytes(unsigned short i) { return (i << 8) | (i >> 8); }