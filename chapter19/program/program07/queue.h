#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define PUBLIC
#define PRIVATE static

// 不完整类型指针别名, 在源文件中定义完整结构体
typedef struct st_queue *Queue;

// 队列接受的数据类型
typedef int Item;

PUBLIC Queue queue_create(void);

PUBLIC void queue_destory(Queue queue);

PUBLIC void queue_append(Queue queue, Item i);

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_remove_head(Queue queue);

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_head(Queue queue);

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_tail(Queue queue);

PUBLIC bool queue_is_empty(Queue queue);

#endif