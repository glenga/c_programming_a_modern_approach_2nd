#include <stdio.h>

unsigned short create_short(unsigned char high_byte, unsigned char low_byte);

int main() {
  char ch1 = 254;
  char ch2 = 255;

  printf("%X\n", create_short(ch2, ch1));

  return 0;
}
unsigned short create_short(unsigned char high_byte, unsigned char low_byte) {
  // return (high_byte << 8) + low_byte;
  return high_byte << 8 | low_byte;
}