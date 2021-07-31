#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int words_count = 0, ch_count = 0;
  char ch;

  printf("Enter a sentence: ");
  while (true) {
    ch = getchar();
    while (!isspace(ch)) {
      ch_count++;
      ch = getchar();
    }

    words_count++;

    while (isspace(ch)) {
      if (ch == '\n')
        goto end;
      ch = getchar();
    }

    ch_count++;
  }

end:
  //   printf("ch_count: %d, words_count: %d.\n", ch_count, words_count);
  printf("Average word length: %.1f", (float)ch_count / (float)words_count);

  return 0;
}

// test: It was deia  yu  all  over  again.