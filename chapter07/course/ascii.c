#include <stdio.h>
#include <stdlib.h>

char *ascii[] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ",  "ACK", "BEL", "BS",
                 "HT",  "LF",  "VT",  "FF",  "CR",  "SO",   "SI",  "DLE", "DC1",
                 "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",  "CAN", "EM",  "SUB",
                 "ESC", "FS",  "GS",  "RS",  "US",  "SPACE"};

int main() {

  printf("dec\thex\tbin\t\tchar\n");
  printf("=====================================\n");

  char buf[10];

  for (int i = 0; i < 128; i++) {
    if (i < 33)
      printf("%-8d%-8X%-16s%-8s\n", i, i, itoa(i, buf, 2), ascii[i]);
    else if (i < 127)
      printf("%-8d%-8X%-16s%-8c\n", i, i, itoa(i, buf, 2), i);
    else
      printf("%-8d%-8X%-16s%-8s\n", i, i, itoa(i, buf, 2), "DEL");
  }

  return 0;
}
