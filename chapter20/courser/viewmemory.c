#include <ctype.h>
#include <stdio.h>

#define ROW 16

typedef unsigned char BYTE;

int main() {
  unsigned int address;
  int n, i;
  BYTE *ptr;

  printf("Address of main function: %x\n", (unsigned int)main);
  printf("Address of address variable: %x\n", (unsigned int)&address);

  printf("Enter a hex address: ");
  scanf("%x", &address);

  printf("Enter number of bytes to view: ");
  scanf("%d", &n);

  printf("\n");
  printf("offset    "
         "                       Bytes                            "
         "   characters   \n");
  printf("--------    "
         "-----------------------------------------------     "
         "----------------\n");

  ptr = (BYTE *)address;
  for (; n > 0; n -= ROW) {
    printf("%8X    ", (unsigned int)ptr);
    for (i = 0; i < ROW && i < n; i++)
      printf("%.2X ", *(ptr + i));
    // 如果一行不满,用空格填充
    for (; i < ROW; i++)
      printf("   ");

    printf("    ");

    for (i = 0; i < ROW && i < n; i++) {
      BYTE ch = *(ptr + i);
      if (!isprint(ch))
        ch = '.';
      printf("%c", ch);
    }

    printf("\n");
    ptr += ROW;
  }

  return 0;
}