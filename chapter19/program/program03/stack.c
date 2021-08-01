/*
这是一个用链表实现的栈

这个版本中存在的问题:
1. 栈空间有上限 (已解决)
2. 栈不能接受不同的数据类型(每次只能接受一种数据类型)
3. 不能定义多个栈同时工作(已解决)
4. 新问题, 多个栈同时工作时只能是相同的数据类型
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// 链表中的节点类型定义
struct node {
  Item data;
  struct node *next;
};

// 定义头文件中的不完整类型, 这个结构的存在是为了兼容接口定义
struct st_stack {
  struct node *top;
  int len;
};

PRIVATE void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC Stack create(void) {
  // 空链表头
  Stack s = malloc(sizeof(struct node));
  if (NULL == s)
    terminate("Error in create: stack could not be created.");

  s->top = NULL;
  s->len = 0;

  return s;
}

PUBLIC void destroy(Stack s) {
  make_empty(s);
  free(s);
}

PUBLIC void make_empty(Stack s) {
  while (!is_empty(s))
    pop(s);
}

PUBLIC bool is_empty(Stack s) { return NULL == s->top; }

PUBLIC bool is_full(Stack s) { return false; }

PUBLIC void push(Stack s, Item i) {
  struct node *new_node = malloc(sizeof(struct node));
  if (NULL == new_node)
    terminate("Error in push: stack is full.");

  new_node->data = i;
  new_node->next = s->top;
  s->top = new_node;
  s->len++;
}

PUBLIC Item pop(Stack s) {
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");

  struct node *old_node = s->top;
  int i = old_node->data;
  s->top = old_node->next;
  free(old_node);

  s->len--;
  return i;
}

PUBLIC Item peek(Stack s) {
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");

  return s->top->data;
}

PUBLIC int length(Stack s) { return s->len; }