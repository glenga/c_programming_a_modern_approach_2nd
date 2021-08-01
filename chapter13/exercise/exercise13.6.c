#include <stdio.h>
#include <string.h>

#define STR_LEN 80

void censor(char *str);

int main() {
  char str[STR_LEN + 1];
  printf("Enter a string with foo: ");
  gets(str);

  censor(str);

  printf("%s", str);
  return 0;
}

void censor(char *str) {
  char *ch = str;
  while (*(ch + 2) != '\0') {
    if (*ch == 'f' && *(ch + 1) == 'o' && *(ch + 2) == 'o')
      *ch = *(ch + 1) = *(ch + 2) = 'x';

    ch++;
  }
}

// test: A fool does not know the word food.