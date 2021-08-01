#include <ctype.h>
#include <stdio.h>

#define STR_LEN 80

int compute_scrabble_value(const char *word);

int main(void) {

  char word[STR_LEN + 1];

  printf("Enter a word: ");
  scanf("%s", word);

  printf("Scrabble value: %d\n", compute_scrabble_value(word));
  return 0;
}

int compute_scrabble_value(const char *word) {
  const int values[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  int sum = 0;

  while (*word)
    sum += values[toupper(*word++) - 'A'];
  return sum;
}

// test: pitfall