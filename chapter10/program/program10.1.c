#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// 外部变量
int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
char push(char ch);
char pop();

int main() {
  bool matched = false;
  char ch, ch_pop = ' ';

  printf("Enter parenteses and/or branches: ");

  while (true) {
    ch = getchar();
    if (ch == '\n' && is_empty() && ch_pop != ' ') {
      matched = true;
      break;
    }

    if (ch == '{' || ch == '(' || ch == '[') {
      push(ch);
      continue;
    } else if (is_empty()) {
      break;
    } else if (!is_empty()) {
      ch_pop = pop();
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

void make_empty(void) { top = 0; }

bool is_empty(void) { return top == 0; }

bool is_full(void) { return top == STACK_SIZE; }

char push(char ch) {
  if (is_full())
    exit(EXIT_FAILURE);
  else {
    contents[top++] = ch;
    return ch;
  }
}

char pop() {
  if (is_empty())
    exit(EXIT_FAILURE);
  else
    return contents[--top];
}

// Enter parenteses and/or branches: ((){}{()})
// Parenteses/braces are nested properly!