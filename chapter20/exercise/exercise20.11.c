#include <stdio.h>

#define SHIFT_BIT 1
#define CTRL_BIT 2
#define ALT_BIT 4

int main() {
  // int key_code = 4; // 100
  int key_code = 7; // 111
  // int key_code = 12; // 1100

  if (key_code & (1 << SHIFT_BIT) || key_code & (1 << CTRL_BIT) ||
      key_code & (1 << ALT_BIT))
    printf("No modifier keys pressed\n");

  return 0;
}