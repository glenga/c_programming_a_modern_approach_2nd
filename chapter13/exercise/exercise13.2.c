#include <stdio.h>
#include <stdlib.h>

int main() {
  char *p = "abc";

  // putchar(p);
  putchar(*p);
  puts(p);
  // puts(*p);

  return 0;
}