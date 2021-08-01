#include "line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60

// char line[MAX_LINE_LEN + 1];
struct node {
  struct node *next;
  char word[];
} *line = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void) {
  struct node *temp;
  while (line) {
    temp = line;
    line = line->next;
    free(temp);
  }
  // line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word) {
  struct node *new_word = malloc(sizeof(struct node) + strlen(word) + 1);
  if (new_word == NULL) {
    printf("Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }
  strcpy(new_word->word, word);
  new_word->next = NULL;

  // 将单词放到行尾
  struct node **pp = &line;
  while (*pp)
    pp = &(*pp)->next; // 注意不是 *pp = (*pp)->next

  *pp = new_word;
  line_len += strlen(word);
  // 每个单词加一个空格.
  if (num_words > 0)
    line_len++;
  // if (num_words > 0) {
  //   line[line_len] = ' ';
  //   line[line_len + 1] = '\0';
  //   line_len++;
  // }
  // strcat(line, word);
  // line_len += strlen(word);
  num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

// void write_line(void) {
//   int extra_spaces, spaces_to_insert;

//   extra_spaces = MAX_LINE_LEN - line_len;
//   for (int i = 0; i < line_len; i++) {
//     if (line[i] != ' ')
//       putchar(line[i]);
//     else {
//       spaces_to_insert = extra_spaces / (num_words - 1);
//       for (int j = 1; j <= spaces_to_insert + 1; j++)
//         putchar(' ');

//       extra_spaces -= spaces_to_insert;
//       num_words--;
//     }
//   }
//   putchar('\n');
// }

void write_line(void) {
  int extra_spaces, spaces_to_insert;
  int char_count = 0;
  struct node *pnode = line;
  extra_spaces = space_remaining();

  while (char_count < line_len && pnode != NULL) {
    printf("%s", pnode->word);
    if (num_words > 1) {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (int i = 1; i <= spaces_to_insert + 1; i++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
    }
    char_count += strlen(pnode->word) + 1;
    num_words--;
    pnode = pnode->next;
  }
  putchar('\n');
}

// void flush_line(void) {
//   if (line_len > 0)
//     puts(line);
// }

void flush_line(void) {
  struct node *pnode = line;
  if (line_len > 0) {
    for (int i = 0; pnode != NULL; i++, pnode = pnode->next) {
      if (i > 0 && pnode->next != NULL)
        putchar(' ');

      printf("%s ", pnode->word);
    }
  }
  printf("\n");
  clear_line();
}