#include <stdbool.h>
#include <stdio.h>

int main() {
  char message[80], ch;
  int n = 0, shift;

  printf("Enter message to be message: ");
  while ((ch = getchar()) != '\n') {
    message[n++] = ch;
  }

  while (true) {
    printf("Enter shift(amount 1-25 ctrl+c quit): ");
    scanf("%d", &shift);

    for (int i = 0; i < n; i++) {
      if (message[i] >= 'A' && message[i] <= 'Z')
        message[i] = (message[i] - 'A' + shift) % 26 + 'A';
      else if (message[i] >= 'a' && message[i] <= 'z')
        message[i] = (message[i] - 'a' + shift) % 26 + 'a';
      else
        message[i] = message[i];
    }

    printf("Encrypted message: ");
    for (int i = 0; i < n; i++)
      printf("%c", message[i]);

    printf("\n");
  }

  return 0;
}

// Enter message to be message: Jr dkhdg, pdnh pb gdb.