#include "stack.h"
#include <stdio.h>

int main() {
  Stack s1, s2;
  char* str;

  s1 = create();
  s2 = create();

  push(s1, "china");
  push(s1, "japan");

  str = pop(s1);
  printf("popped %s from s1\n", str);
  push(s2, str);
  str = pop(s1);
  printf("popped %s from s1\n", str);
  push(s2, str);

  destroy(s1);

  while (!is_empty(s2))
    printf("popped %s from s2\n", pop(s2));

  push(s2, "germany");
  make_empty(s2);
  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  return 0;
}

// test: gcc -o stack.exe  stack.h stack.c main.c