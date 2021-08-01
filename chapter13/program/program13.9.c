#include <ctype.h>
#include <stdio.h>

#define STR_LEN 80

int compute_vowel_count(const char *sentence);

int main(void) {

  char sentence[STR_LEN + 1];
  char c, *p = sentence;

  printf("Enter a sentence: ");
  while ((c = getchar()) != '\n' && p < sentence + 80)
    *p++ = c;
  p = '\0';

  printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));
  return 0;
}

int compute_vowel_count(const char *sentence) {
  int count = 0;
  while (*sentence) {
    switch (toupper(*sentence)) {
    case 'A':
    case 'E':
    case 'O':
    case 'I':
    case 'U':
      count++;
      break;
    default:
      break;
    }
    sentence++;
  }

  return count;
}

// test: And that's the way it is.