#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define RPN_LEN 80
#define STACK_SIZE 100

// 外部变量
int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
int push(int num);
int pop();

int evaluate_RPN_expression(const char *expression);

int main() {
  char rpn[RPN_LEN + 1];
  printf("Enter an RPN expression: ");
  fgets(rpn, sizeof(rpn), stdin);

  printf("Value of expression: %d\n", evaluate_RPN_expression(rpn));
  return 0;
}

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  while (*expression != '=') {
    if (isdigit(*expression))
      push(*expression - '0');
    else if (*expression == '+')
      push(pop() + pop());
    else if (*expression == '-') {
      op1 = pop();
      op2 = pop();
      push(op2 - op1);
    } else if (*expression == '*')
      push(pop() * pop());
    else if (*expression == '/') {
      op1 = pop();
      op2 = pop();
      push(op2 / op1);
    } else if (*expression == 'q')
      exit(EXIT_SUCCESS);

    expression++;
  }

  return pop();
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