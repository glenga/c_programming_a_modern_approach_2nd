#include <stdio.h>
#include <time.h>
#include <tgmath.h>

int main() {
  time_t cur = time(NULL);
  struct tm *p = localtime(&cur);

  char s[50];

  // a
  strftime(s, sizeof(s), "%A, %B %d, %Y  %I:%M", p);
  printf("%s%c\n", s, p->tm_hour <= 11 ? 'a' : 'p');

  // b
  strftime(s, sizeof(s), "%a, %d %b %y  %H:%M", localtime(&cur));
  printf("%s\n", s);

  // c
  strftime(s, sizeof(s), "%x %X %p", localtime(&cur));
  printf("%s\n", s);

  return 0;

}