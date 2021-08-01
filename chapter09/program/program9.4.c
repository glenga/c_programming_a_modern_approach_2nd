#include <ctype.h>
#include <stdio.h>

#define NUMS_OF_ALPHABET 26

void read_word(int counts[26]);
void equal_array(int counts1[26], int counts2[26]);

int main() {
  int first[NUMS_OF_ALPHABET] = {0};
  int second[NUMS_OF_ALPHABET] = {0};

  printf("Enter first word: ");
  read_word(first);
  printf("Enter second word: ");
  read_word(second);

  equal_array(first, second);

  return 0;
}

// 单词录入数组
void read_word(int counts[26]) {
  char ch;
  while ((ch = getchar()) != '\n') {
    ch = tolower(ch);
    counts[ch - 'a']++;
  }
}

// 单词比较
void equal_array(int counts1[26], int counts2[26]) {
  int i;
  for (i = 0; i < NUMS_OF_ALPHABET; i++) {
    if (counts1[i] != counts2[i]) {
      printf("The words are not anagrams.");
      break;
    }
  }

  if (i >= NUMS_OF_ALPHABET) {
    printf("The words are anagrams.");
  }
}

// Enter first word: smartest
// Enter second word: mattress