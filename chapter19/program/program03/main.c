#include "stack.h"
#include <stdio.h>

int main() {
  Stack s1, s2;
  int n;

  s1 = create();
  s2 = create();

  push(s1, 1);
  push(s1, 2);

  n = pop(s1);
  printf("popped %d from s1 ,s1 length: %d\n", n, length(s1));
  push(s2, n);
  n = pop(s1);
  printf("popped %d from s1, s1 length: %d\n", n, length(s1));
  push(s2, n);

  destroy(s1);

  while (!is_empty(s2))
    printf("popped %d from s2, s2 length: %d\n", pop(s2), length(s2));

  push(s2, 3);
  make_empty(s2);
  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  return 0;
}

// test: gcc -o stack.exe  stack.h stack.c main.c