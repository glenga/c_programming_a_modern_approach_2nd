#include <stdio.h>
#include <string.h>

void remove_filename(char *url);

int main() {
  char url[] = "http://www.knking.com/index.html";

  remove_filename(url);

  printf("%s", url);

  return 0;
}

void remove_filename(char *url) {
  int n = strlen(url);
  char *tail = url + n;

  while (n-- >= 0) {
    if (*tail == '/') {
      *tail = '\0';
      break;
    }
    tail--;
  }

}