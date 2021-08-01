#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 100

// 外部变量
int contents[STACK_SIZE];
int top = 0;

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
