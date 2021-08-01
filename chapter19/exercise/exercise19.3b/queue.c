#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

#define QUEUE_SIZE 5

// 增加节点定义
struct node {
  Item data;
  struct node *next;
};

// 修改队列结构定义
struct st_queue {
  struct node *head;
  struct node *tail;
};

PRIVATE void message(char *str) { printf("%s\n", str); }

PUBLIC Queue queue_create(void) {
  // 分配队列指针空间
  Queue queue = malloc(sizeof(struct st_queue));
  if (NULL == queue) {
    message("Error in create: not enough memory!");
    return NULL;
  }

  queue->tail = queue->head = NULL;

  return queue;
}

PUBLIC void queue_destory(Queue queue) {
  struct node *temp;
  while (queue->head) {
    temp = queue->head;
    queue->head = temp->next;
    free(temp);
  }

  free(queue);
}

PUBLIC void queue_append(Queue queue, Item i) {
  struct node *new_node = malloc(sizeof(struct node));
  if (NULL == new_node) {
    message("Error in create: not enough memory!");
    return;
  }

  new_node->data = i;
  new_node->next = NULL;

  if (NULL == queue->tail) {
    queue->head = queue->tail = new_node;
  } else {
    queue->tail->next = new_node;
    queue->tail = new_node;
  }
}

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_remove_head(Queue queue) {
  struct node *removed_node = queue->head;
  Item data = removed_node->data;

  queue->head = removed_node->next;
  free(removed_node);

  return data;
}

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_head(Queue queue) { return queue->head->data; }

// 调用前先检查数据, 确保数据存在
PUBLIC Item queue_tail(Queue queue) { return queue->tail->data; }

PUBLIC bool queue_is_empty(Queue queue) {
  return NULL == queue->head && NULL == queue->tail;
}
