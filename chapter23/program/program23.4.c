#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  char str[BUFSIZ];

  printf("Enter word string: ");
  fgets(str, BUFSIZ, stdin);

  int ch_count = strlen(str);

  char *p = strtok(str, " \n\t\r");
  while (p) {
    puts(p);
    p = strtok(NULL, " \n\t\r");
  }

  p = &str[ch_count];
  while (true) {
    p--;
    if (p == str) {
      puts(p);
      break;
    } else if (*p == '\0')
      puts(p + 1);
  }

  return 0;
}

// test: Enter word string: hello break red read blue ubuntu deepin word