#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *str);

int main() {

  char *str = "hello world!!";
  char *new_str = duplicate(str);
  printf("str address: %p  new_str address: %p\n%s\n", str, new_str, new_str);

  return 0;
}

char *duplicate(char *str) {
  char *p = (char *)malloc(strlen(str));
  if (p == NULL) {
    printf("Error: malloc failed!\n");
    return NULL;
  }
  strcpy(p, str);
  return p;
}