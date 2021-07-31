#include <ctype.h>
#include <stdio.h>

int main() {
  int n = 0;
  printf("Enter a sentence: ");
  char ch;

  while ((ch = getchar()) != '\n') {
    switch (towlower(ch)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      n++;
      break;
    default:
      continue;
    }
  }

  printf("Your sentence contains %d Vowels.", n);
  return 0;
}

// test: And that's the way it is.