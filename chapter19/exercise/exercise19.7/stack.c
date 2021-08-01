/*
这是一个用动态数组实现的栈

这个版本中存在的问题:
1. 栈空间有上限 (可以修改代码动态增加内存)
2. 栈不能接受不同的数据类型(每次接受一种数据类型)
3. 不能定义多个栈同时工作(已解决)
4. 新问题, 多个栈同时工作时只能是相同的数据类型
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// 定义头文件中的不完整类型
struct st_stack {
  Item *contents;
  int top;
  int size;
};

// c标准中 realloc 函数的几条规则
PRIVATE void resize_contents(Stack s) {
  Item *re_contents = realloc(s->contents, (s->size *= 2) * sizeof(Item));
  if (NULL == re_contents) {
    printf("Error in resize_contents.\n");
    return;
  }

  if (re_contents != s->contents) {
    free(s->contents);
    s->contents = re_contents;
  }
}

PRIVATE void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC Stack create(int size) {
  // 先创建栈指针空间
  Stack s = malloc(sizeof(struct st_stack));
  if (NULL == s)
    terminate("Error in create: stack could not be created.");
  // 再创建栈空间
  s->contents = malloc((sizeof(Item) * size));
  if (NULL == s->contents)
    terminate(("Error in create: stack could not be created."));

  s->top = 0;
  s->size = size;
  return s;
}

PUBLIC void destroy(Stack s) {
  free(s->contents);
  free(s);
}

PUBLIC void make_empty(Stack s) { s->top = 0; }

PUBLIC bool is_empty(Stack s) { return 0 == s->top; }

PUBLIC bool is_full(Stack s) { return s->size == s->top; }

// 动态加倍
PUBLIC void push(Stack s, Item i) {
  if (is_full(s))
    resize_contents(s);

  s->contents[s->top++] = i;
}

PUBLIC Item pop(Stack s) {
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");

  return s->contents[--s->top];
}

PUBLIC Item peek(Stack s) {
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");

  return s->contents[s->top - 1];
}