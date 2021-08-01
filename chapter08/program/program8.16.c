#include <ctype.h>
#include <stdio.h>

#define NUMS_OF_ALPHABET 26

int main() {
  int ch_count1[NUMS_OF_ALPHABET] = {0};
  int ch_count2[NUMS_OF_ALPHABET] = {0};

  char ch;

  printf("Enter first word: ");
  while ((ch = getchar()) != '\n') {
    ch = tolower(ch);
    ch_count1[ch - 'a']++;
  }

  printf("Enter second word: ");
  while ((ch = getchar()) != '\n') {
    ch = tolower(ch);
    ch_count2[ch - 'a']++;
  }

  // 下面这个if 分支永远无法到达!

  // for (int i = 0; i < NUMS_OF_ALPHABET; i++) {
  //   if (i >= NUMS_OF_ALPHABET) {
  //     printf("The words are anagrams.");
  //   } else if (ch_count1[i] != ch_count2[i]) {
  //     printf("The words are not anagrams.");
  //     break;
  //   }

  int i;
  for (i = 0; i < NUMS_OF_ALPHABET; i++) {
    if (ch_count1[i] != ch_count2[i]) {
      printf("The words are not anagrams.");
      break;
    }
  }

  if (i >= NUMS_OF_ALPHABET) {
    printf("The words are anagrams.");
  }

  return 0;
}

// test: smartest    Mattress
// test: dumbest   stumble