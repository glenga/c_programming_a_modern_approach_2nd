/*
这是一个用链表实现的栈

这个版本中存在的问题:
1. 栈空间有上限 (已解决)
2. 栈不能接受不同的数据类型
3. 不能定义多个栈同时工作
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

// 在这个设计中, 所有数据结构均被隐藏,仅仅提供了访问数据的接口
PRIVATE struct node *top = NULL;
PRIVATE void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC void make_empty(void) {
  while (!is_empty())
    pop();
}

PUBLIC bool is_empty() { return NULL == top; }

PUBLIC bool is_full() { return false; }

PUBLIC void push(int i) {
  struct node *new_node = malloc(sizeof(struct node));
  if (NULL == new_node)
    terminate("Error in push: stack is full.");

  new_node->data = i;
  new_node->next = top;
  top = new_node;
}

PUBLIC int pop(void) {
  if (is_empty())
    terminate("Error in pop: stack is empty.");

  int i = top->data;
  struct node *old_top = top;
  top = top->next;
  free(old_top);
  return i;
}