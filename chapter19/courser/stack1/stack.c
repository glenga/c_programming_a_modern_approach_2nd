/*
这是一个用数组实现的栈

这个版本中存在的问题:
1. 栈空间有上限
2. 栈不能接受不同的数据类型
3. 不能定义多个栈同时工作
4. 内部实现数据结构暴露
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// 文件作用域, (对外隐藏, 实现封装)
PRIVATE int contents[STACK_SIZE];
PRIVATE int top = 0;

// 文件作用域, (对外隐藏, 实现封装)
PRIVATE void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC void make_empty(void) { top = 0; }

PUBLIC bool is_empty(void) { return top == 0; }

PUBLIC bool is_full(void) { return top == STACK_SIZE; }

PUBLIC void push(int i) {
  if (is_full())
    terminate("Error in push: stack is full.");

  contents[top++] = i;
}

PUBLIC int pop(void) {
  if (is_empty())
    terminate("Error in pop: stack is empty.");

  return contents[--top];
}