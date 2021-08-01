#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

// #define QUEUE_SIZE 5

// struct st_queue {
//   Item contents[QUEUE_SIZE];
//   int head;
//   int tail;
//   int items;
// };


PRIVATE void message(char *str) { printf("%s\n", str); }

// PUBLIC Queue queue_create(void) {
//   Queue *queue = malloc(sizeof(struct st_queue));
//   if (NULL == queue) {
//     message("Error in create: not enough memory!");
//     exit(EXIT_FAILURE);
//   }
//   queue->head = 0;
//   queue->tail = 0;
//   queue->items = 0;

//   return *queue;
// }

// PUBLIC void queue_destory(Queue* queue) { free(queue); }

//            tail      head
//             ↓ ⇢      ↓ ⇢
//  _______________________________________
// | a5| a6 |    |    | a1 | a2 | a3 | a4 |
// |--------------------------------------|
//   0   1    2    3    4    5    6    7
//

PUBLIC void queue_append(Queue *queue, Item i) {
  if (queue->items > 0 && (queue->head + queue->tail) % QUEUE_SIZE == 0) {
    message("Error in append: queue is full!");
    return;
  }
  queue->contents[queue->tail] = i;
  queue->tail = (queue->tail + 1) % QUEUE_SIZE;
  queue->items++;
}

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_remove_head(Queue *queue) {
  Item data = queue->contents[queue->head];
  queue->head = (queue->head + 1) % QUEUE_SIZE;
  queue->items--;
  return data;
}

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_head(Queue *queue) { return queue->contents[queue->head]; }

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_tail(Queue *queue) {
  return queue->contents[(queue->tail - 1 + QUEUE_SIZE) % QUEUE_SIZE];
}

PUBLIC bool queue_is_empty(Queue *queue) { return 0 == queue->items; }
