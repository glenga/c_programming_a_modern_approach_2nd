#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20
#define MAX_RECORD 20

int read_word(char word[], int n);
int compare(const void *str1, const void *str2);

int main() {
  char word[WORD_LEN + 1];
  char *records[MAX_RECORD];
  int num_records = 0;

  while (read_word(word, WORD_LEN)) {
    // puts(word);
    records[num_records] = malloc(strlen(word) + 1);
    if (NULL == records[num_records]) {
      printf("No space left.\n");
      exit(EXIT_FAILURE);
    }
    strcpy(records[num_records], word);
    num_records++;
  }

  qsort(records, num_records, sizeof(char *), compare);

  printf("In sorted order: ");
  for (int i = 0; i < num_records; i++)
    printf("%s ", records[i]);

  printf("\n");
  return 0;
}

int read_word(char word[], int n) {
  int ch, i = 0;
  printf("Enter word: ");
  while ((ch = getchar()) == ' ')
    ;

  while (!isspace(ch)) {
    if (i < n)
      word[i++] = ch;

    ch = getchar();
  }
  word[i] = '\0';

  return i;
}

int compare(const void *str1, const void *str2) {
  return strcmp(*(char **)str1, *(char **)str2);
}

// Enter word: hello
// Enter word: foo
// Enter word: bar
// Enter word: baz
// Enter word: quux
// Enter word:
// In sorted order: hello foo bar baz quux