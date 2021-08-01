#include "stack.h"
#include <stdio.h>

int main() {
  for (int i = 0; i < 10; i++)
    push(i + 100);

  while (!is_empty())
    printf("%d \n", pop());
  return 0;
}

// test: gcc -o stack.exe  stack.h stack.c main.c