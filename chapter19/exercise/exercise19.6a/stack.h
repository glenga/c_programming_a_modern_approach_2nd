#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define PUBLIC
#define PRIVATE static // 文件作用域 隐藏

// 利用不完整类型声明一个指针别名,
// struct st_stack结构会在源文件中定义, 实现方式不影响接口定义
typedef struct st_stack *Stack;

// 利用类型别名限制stack接受的数据类型
typedef int Item;

// 利用别名定义接口
PUBLIC Stack create(void);

PUBLIC void destroy(Stack s);

PUBLIC void make_empty(Stack s);

PUBLIC bool is_empty(Stack s);

PUBLIC bool is_full(Stack s);

PUBLIC void push(Stack s, Item i);

PUBLIC Item pop(Stack s);

PUBLIC Item peek(Stack s);

#endif