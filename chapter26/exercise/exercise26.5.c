#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vstrcat(const char *first, ...);

int main() {

  printf("%s\n",
         vstrcat("I", "am", "chinese", "my", "english", "very", "pool", 0));

  return 0;
}

char *vstrcat(const char *first, ...) {
  int ch_count = strlen(first);
  char *p;

  va_list ap;
  va_start(ap, first); // ap 从 start 的下一个元素开始
  while ((p = va_arg(ap, char *)) != (char *)NULL)
    ch_count += strlen(p);

  char *ret_p = malloc(sizeof(char) * ch_count + 1); // 1 for '\0'
  if (NULL == ret_p) {
    fprintf(stderr, "not enough memory!\n");
    va_end(ap);
    return NULL;
  }

  strcpy(ret_p, first);

  va_start(ap, first); // ap 从 start 的下一个元素开始
  while ((p = va_arg(ap, char *)) != (char *)NULL)
    strcat(ret_p, p);

  va_end(ap);

  return ret_p;
}