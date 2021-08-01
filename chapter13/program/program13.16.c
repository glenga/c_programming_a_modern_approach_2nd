#include <stdio.h>
#include <string.h>

#define MSG_LEN 80

void reverse(char *message);

int main() {
  char message[MSG_LEN + 1];
  printf("Enter the message: ");
  fgets(message, sizeof(message), stdin);
  reverse(message);

  printf("Reversal message: %s\n", message);

  return 0;
}

void reverse(char *message) {
  char *head = message, *tail = message + strlen(message) - 1;
  char tmp;
  while (head < tail) {
    tmp = *head;
    *head++ = *tail;
    *tail-- = tmp;
  }
}

// test: i'm a chinese.