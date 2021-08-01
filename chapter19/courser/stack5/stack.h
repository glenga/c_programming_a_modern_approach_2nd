#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define PUBLIC
#define PRIVATE static // 文件作用域 隐藏

// 利用不完整类型声明一个指针别名,
// struct st_stack结构会在源文件中定义, 实现方式不影响接口定义
typedef struct st_stack *Stack;

// 利用别名定义接口
PUBLIC Stack create(void);

PUBLIC void destroy(Stack s);

PUBLIC void make_empty(Stack s);

PUBLIC bool is_empty(Stack s);

PUBLIC bool is_full(Stack s);

// 利用 void * 通用类型,接收各种类型的指针数据
PUBLIC void push(Stack s, void *p);

PUBLIC void *pop(Stack s);

#endif