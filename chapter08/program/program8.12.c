#include <ctype.h>
#include <stdio.h>

int main() {
  const int array[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                       1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

  printf("Enter a word: ");

  char ch;
  int sum = 0;
  while ((ch = getchar()) != '\n') {
    ch = toupper(ch);
    sum += array[ch - 'A'];
  }

  printf("Scrabble: %d", sum);

  return 0;
}

// Enter a word: pitfall