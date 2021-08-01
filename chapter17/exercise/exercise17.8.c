#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *top = NULL;

void make_empty(void) {
  struct node *temp;
  while (top) {
    temp = top;
    top = top->next;
    free(temp);
  }
}

bool is_empty(void) { return top == NULL; }

bool push(int i) {
  struct node *new_node = malloc(sizeof(struct node));
  if (NULL == new_node)
    return false;

  new_node->value = i;
  new_node->next = top;
  top = new_node;

  return true;
}

int pop(void) {
  if (is_empty()) {
    printf("Error: stack underflow\n");
    exit(EXIT_FAILURE);
  }

  struct node *temp = top;
  int i = top->value;
  top = top->next;

  free(temp);
  return i;
}

int main() {
  int i;
  for (i = 0; i < 5; i++)
    push(i + 100);

  while (--i >= 0) {
    printf("pop : %d\n", pop());

  }

  for (i = 0; i < 5; i++)
    push((i + 200));

  printf("pop : %d\n", pop());
  make_empty();

  return 0;
}
