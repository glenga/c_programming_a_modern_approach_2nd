#include <stdio.h>

int main() {
  char ch;
  int len = 0;

  printf("Enter a message: ");

  ch = getchar();

  while (ch != '\n') {
    len++;
    ch = getchar();
  }

  printf("Your message was %d character(s) long.\n", len);

  return 0;
}

// Enter a message: Brevity is the soul of wit.