#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define WORD_LEN 20

int main() {
  char word[WORD_LEN + 1];
  char smallest_word[WORD_LEN + 1], largest_word[WORD_LEN + 1];

  printf("Enter word: ");
  scanf("%s", word);
  sprintf(smallest_word, "%s", word);
  sprintf(largest_word, "%s", word);

  while (true) {
    printf("Enter word: ");
    scanf("%s", word);
    if (strcmp(word, largest_word) > 0)
      sprintf(largest_word, "%s", word);
    else if (strcmp(word, smallest_word) < 0)
      sprintf(smallest_word, "%s", word);

    if (strlen(word) == 4)
      break;
  }

  printf("Smallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);
  return 0;
}

// Enter word: dog
// Enter word: zebra
// Enter word: rabbit
// Enter word: catfish
// Enter word: walrus
// Enter word: cat
// Enter word: fish