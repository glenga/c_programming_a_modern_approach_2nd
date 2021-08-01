#ifndef STACK_H
#define STACK_H

#define PUBLIC
#define PRIVATE static  // 文件作用域 隐藏

#include <stdbool.h>

PUBLIC void make_empty(void);

PUBLIC bool is_empty(void);

PUBLIC bool is_full(void);

PUBLIC void push(int i);

PUBLIC int pop(void);

#endif