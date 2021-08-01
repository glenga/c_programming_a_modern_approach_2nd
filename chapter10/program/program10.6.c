#include <ctype.h> // for isdigit()
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
int push(int num);
int pop();

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

void make_empty(void) { top = 0; }

bool is_empty(void) { return top == 0; }

bool is_full(void) { return top == STACK_SIZE; }

int push(int num) {
  if (is_full()) {
    printf("Expression is too complex.\n");
    exit(EXIT_FAILURE);
  } else {
    contents[top++] = num;
    return num;
  }
}

int pop() {
  if (is_empty()) {
    printf("Not enough operands in expression.");
    exit(EXIT_FAILURE);
  } else {
    return contents[--top];
  }
}

// test: 1 2 3 * + =
// test: 5 8 * 4 9 - / =