#include "queue.h"
#include <stdio.h>

int main() {
  Queue queue = queue_create();

  printf("operating append:\n\n");

  for (int i = 0; i < 7; i++) {
    queue_append(queue, i + 100);
    printf("queue head: %d, queue tail: %d\n\n", queue_head(queue),
           queue_tail(queue));
  }

  printf("\noperating remove:\n\n");

  for (int i = 0; i < 7; i++) {
    if (!queue_is_empty(queue)) {
      printf("queue head: %d, queue tail: %d\n\n", queue_head(queue),
             queue_tail(queue));
      queue_remove_head(queue);
    }
  }

  queue_destory(queue);
  return 0;
}

// test: gcc -o queue.exe queue.c main.c