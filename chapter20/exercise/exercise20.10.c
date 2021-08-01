#include <stdio.h>

unsigned int reverse_bits(unsigned int n);

int main() {
  unsigned int ch;

  printf("unsigned int max is %X, %u bit\n\n", __UINT32_MAX__,
         (unsigned int)sizeof(int) * 8);

  printf("Enter the hex digit: ");
  scanf("%x", &ch);

  unsigned int reverse = reverse_bits(ch);

  printf("the digit reverse with bit： %.8X\n", reverse);

  return 0;
}

/*
1<<bit_index-i
     ↓      1<<i
     x       y
     ↓       ↓
0000,0000,1111,1111
     ↑       ↑
     ↑       1,0000 // 构建的掩码
     1000,0000,0000 // 构建的掩码


如果 x 位是0， y位为0， 交换后 x 位应该为 0
如果 x 位是0， y位为1， 交换后 x 位应该为 1
如果 x 位是1， y位为0， 交换后 x 位应该为 0
如果 x 位是1， y位为1， 交换后 x 位应该为 1

除了x = y 不用交换，其余情况就是一个异或操作
*/

unsigned int reverse_bits(unsigned int n) {
  unsigned int i, bits_index = sizeof(int) * 8 - 1;

  for (i = 0; i <= (unsigned int)bits_index / 2; i++) {
    // x!=y
    if (((n >> (bits_index - i)) & 1) != ((n >> i) & 1)) {
      // 设置x位
      n ^= 1 << (bits_index - i);
      // 设置y位
      n ^= (1 << i);
    }

    if ((i + 1) % 4 == 0)
      printf(" %2u changed : %.8X\n", i + 1, n);
  }
  return n;
}

// Enter the hex digit: FFFF0000
// the digit reverse with bit： 0000FFFF

// Enter the hex digit: FFFF
// the digit reverse with bit： FFFF0000