#include <ctype.h>
#include <stdio.h>

#define STR_LEN 100

double compute_average_word_length(const char *sentence);

int main() {
  char sentence[STR_LEN + 1];

  printf("Enter a sentence: ");
  fgets(sentence, sizeof(sentence), stdin);

  printf("Average word length: %.1f\n", compute_average_word_length(sentence));

  return 0;
}

double compute_average_word_length(const char *sentence) {
  int words = 0, length = 0;
  while (*sentence) {
    while (*sentence && !isspace(*sentence)) {
      sentence++;
      length++;
    }
    words++;
    while (*sentence && isspace(*sentence))
      sentence++;
  }

  return (double)length / words;
}

// test: It was deia yu all over again.