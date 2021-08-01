#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define WORDS_LEN 80
#define NUMS_OF_ALPHABET 26

bool are_anagrams(const char *word1, const char *word2);
void get_word(char *word);

int main() {
  char word1[WORDS_LEN + 1];
  char word2[WORDS_LEN + 1];

  printf("Enter first word: ");
  // fgets(word1, sizeof(word1), stdin);
  get_word(word1);

  printf("Enter second word: ");
  // fgets(word2, sizeof(word2), stdin);
  get_word(word2);

  if (are_anagrams(word1, word2))
    printf("The words are not anagrams.");
  else
    printf("The words are anagrams.");

  return 0;
}

bool are_anagrams(const char *word1, const char *word2) {
  int ch_count1[NUMS_OF_ALPHABET] = {0};
  int ch_count2[NUMS_OF_ALPHABET] = {0};

  while (*word1++)
    ++ch_count1[*word1 - 'a'];

  while (*word2++)
    ++ch_count2[*word2 - 'a'];

  for (int i = 0; i < NUMS_OF_ALPHABET; i++) {
    if (ch_count1[i] != ch_count2[i])
      return false;
  }

  return true;
}

void get_word(char *word) {
  char ch;
  while ((ch = getchar()) != '\n') {
    *word++ = tolower(ch);
  }
  *word = '\0';
}

// test: smartest    Mattress
// test: dumbest   stumble