#include "stack.h"
#include <ctype.h> // for isdigit()
#include <stdio.h>
#include <stdlib.h>

int main() {
  char ch;
  int op1, op2;
  printf("Enter an RPN expression: ");

  while (true) {
    scanf(" %c", &ch);
    if (isdigit(ch)) {
      // printf("now push => %d\n", ch - '0');
      push(ch - '0');
    } else if (ch == '+') {
      op2 = pop();
      op1 = pop();
      push(op1 + op2);
    } else if (ch == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (ch == '*') {
      op2 = pop();
      op1 = pop();
      push(op1 * op2);
    } else if (ch == '/') {
      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (ch == '=') {
      printf("Value of expression: %d\n", pop());
      printf("Enter an RPN expression: ");
    } else if (ch == 'q')
      exit(EXIT_SUCCESS);
  }
  return 0;
}

// test: 1 2 3 * + =
// test: 5 8 * 4 9 - / =