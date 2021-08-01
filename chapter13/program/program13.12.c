#include <ctype.h>
#include <stdio.h>

#define MAX_WORDS 30
#define MAX_LEN 20

int main(void) {

  int words_count = 0, ch_count = 0;
  char ch;
  char terminating_char = 0;
  char sentence[MAX_WORDS][MAX_LEN + 1];

  printf("Enter   a   sentence: ");
  while ((ch = getchar()) != '\n' && words_count < MAX_WORDS) {
    if (isspace(ch)) {
      sentence[words_count][ch_count] = '\0';
      words_count++;
      ch_count = 0;
      continue;
    }

    if (ch == '.' || ch == '!' || ch == '?') {
      terminating_char = ch;
      sentence[words_count][ch_count] = '\0';
      break;
    } else if (ch_count < MAX_LEN)
      sentence[words_count][ch_count++] = ch;
  }

  printf("Reversal of sentence: ");
  while (words_count > 0)
    printf("%s ", sentence[words_count--]);

  printf("%s%c\n", sentence[words_count], terminating_char);

  return 0;
}

// test:    you  can    cage  a swallow can't  you ?