#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char *max_pair(int num_pairs, ...);

int main() {
  char * str;
  str = max_pair(5, 180, "Seinfeld", 180, "I Love Lucy", 39, "The Honeymooners", 210,
           "All in the Family", 86, "The Sopranos");

  printf("%s\n", str);

  return 0;
}

char *max_pair(int num_pairs, ...) {
  int num, max = 0;
  char *str, *ret;

  va_list ap;
  va_start(ap, num_pairs);

  while (num_pairs > 0) {
    num = va_arg(ap, int);
    str = va_arg(ap, char *);

    if (num > max) {
      max = num;
      ret = str;
    }

    num_pairs--;
  }

  va_end(ap);
  return ret;
}