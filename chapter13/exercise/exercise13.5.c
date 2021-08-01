#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void capitalize_a(char str[]);
void capitalize_b(char *str);

#define LEN_STR 50

int main() {
  char str[LEN_STR + 1];

  printf("Enter string: ");
  gets(str);

  // capitalize_a(str);
  capitalize_b(str);

  printf("%s", str);

  return 0;
}

void capitalize_a(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    if (isalpha(str[i]))
     str[i] = toupper(str[i]);
    i++;
  }
}

void capitalize_b(char *str) {
  char *p = str;
  while (*p != '\0') {
    if (isalpha(*p))
       *p = toupper(*p);
    p++;
  }
}

// // test:    China is great, I love china!