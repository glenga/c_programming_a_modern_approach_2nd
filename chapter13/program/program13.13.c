#include <stdbool.h>
#include <stdio.h>

#define MSG_LEN 80

void encrypt(char *message, int shift);

int main() {
  char msg[MSG_LEN + 1];
  int shift;

  printf("Enter message to be message: ");
  fgets(msg, sizeof(msg), stdin);

  while (true) {
    printf("Enter shift amount(1-25) or ctrl+c quit: ");
    scanf("%d", &shift);

    encrypt(msg, shift);

    printf("Encrypted message: %s\n", msg);
  }

  return 0;
}

void encrypt(char *message, int shift) {
  while (*message) {
    if (*message >= 'A' && *message <= 'Z')
      *message = (*message - 'A' + shift) % 26 + 'A';
    else if (*message >= 'a' && *message <= 'z')
      *message = (*message - 'a' + shift) % 26 + 'a';

    message++;
  }
}

// test: Jr dkhdg, pdnh pb gdb.