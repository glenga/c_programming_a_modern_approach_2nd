#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "parameter error!\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "rb");
  if (NULL == fp) {
    fprintf(stderr, "error open file: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  int orig_char, new_char;
  while ((orig_char = getc(fp)) != EOF) {
    new_char = orig_char ^ KEY;
    // if (isprint(orig_char) && isprint(new_char))
    //   putchar(new_char);
    // else
    //   putchar(orig_char);
    putchar(new_char);
  }

  return 0;
}

// program22.5.exe msg >newmsg
// program22.5.exe newmsg