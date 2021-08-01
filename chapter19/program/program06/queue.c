#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

#define QUEUE_SIZE 5

struct st_queue {
  Item *contents;
  int head;
  int tail;
  int items;
  // 需要添加变量存储队列分配的内存空间
  int queue_size;
};

PRIVATE void message(char *str) { printf("%s\n", str); }

PUBLIC Queue queue_create(int size) {
  // 分配队列空间
  Queue queue = malloc(sizeof(struct st_queue));
  if (NULL == queue) {
    message("Error in create: not enough memory!");
    return NULL;
  }
  // 分配数组空间
  queue->contents = malloc(sizeof(Item) * size);
  if (NULL == queue->contents) {
    message("Error in create: not enough memory!");
    free(queue);
    return NULL;
  }
  queue->queue_size = size;

  queue->head = 0;
  queue->tail = 0;
  queue->items = 0;

  return queue;
}

PUBLIC void queue_destory(Queue queue) {
  free(queue->contents);
  free(queue);
}

//            tail      head
//             ↓ ⇢      ↓ ⇢
//  _______________________________________
// | a5| a6 |    |    | a1 | a2 | a3 | a4 |
// |--------------------------------------|
//   0   1    2    3    4    5    6    7
//

PUBLIC void queue_append(Queue queue, Item i) {
  if (queue->items > 0 &&
      (queue->head + queue->tail) % queue->queue_size == 0) {
    message("Error in append: queue is full!");
    return;
  }
  queue->contents[queue->tail] = i;
  queue->tail = (queue->tail + 1) % queue->queue_size;
  queue->items++;
}

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_remove_head(Queue queue) {
  Item data = queue->contents[queue->head];
  queue->head = (queue->head + 1) % queue->queue_size;
  queue->items--;
  return data;
}

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_head(Queue queue) { return queue->contents[queue->head]; }

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_tail(Queue queue) {
  return queue
      ->contents[(queue->tail - 1 + queue->queue_size) % queue->queue_size];
}

PUBLIC bool queue_is_empty(Queue queue) { return 0 == queue->items; }
