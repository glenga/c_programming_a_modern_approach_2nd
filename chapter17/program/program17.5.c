#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20
#define MAX_RECORD 20

int read_word(char word[], int n);

int main() {
  char word[WORD_LEN + 1];
  char *records[MAX_RECORD] = {NULL};
  int num_records = 0;

  while (read_word(word, WORD_LEN)) {
    // puts(word);
    char *temp = malloc(strlen(word) + 1);
    if (NULL == temp) {
      printf("No space left.\n");
      exit(EXIT_FAILURE);
    }
    strcpy(temp, word);

    int i;
    // 找到"小"的位置
    for (i = 0; i < num_records; i++) {
      if (strcmp(temp, records[i]) < 0)
        break;
    }

    // 将后面的全部移一位
    for (int j = num_records; j > i; j--)
      records[j] = records[j - 1];

    // 插入
    records[i] = temp;

    num_records++;
  }

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

// Enter word: hello
// Enter word: foo
// Enter word: bar
// Enter word: baz
// Enter word: quux
// Enter word:
// In sorted order: hello foo bar baz quux