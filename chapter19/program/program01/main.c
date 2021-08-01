#include "stack.h"
#include <stdbool.h>
#include <stdio.h>

int main() {

  Stack s = create();

  bool matched = false;
  char ch, ch_pop = ' ';

  printf("Enter parenteses and/or branches: ");

  while (true) {
    ch = getchar();
    if (ch == '\n' && is_empty(s) && ch_pop != ' ') {
      matched = true;
      break;
    }

    if (ch == '{' || ch == '(' || ch == '[') {
      push(s, ch);
      continue;
    } else if (is_empty(s)) {
      break;
    } else if (!is_empty(s)) {
      ch_pop = pop(s);
      if (ch_pop == '}' && ch != '{') {
        break;
      } else if (ch_pop == '(' && ch != ')') {
        break;
      } else if (ch_pop == '[' && ch != ']') {
        break;
      } else
        continue;
    }
  }

  if (matched)
    printf("Parenteses/braces are nested properly!\n");
  else
    printf("Parenteses/braces not nested properly!\n");

  return 0;
}

// Enter parenteses and/or branches: ((){}{()})
// Parenteses/braces are nested properly!