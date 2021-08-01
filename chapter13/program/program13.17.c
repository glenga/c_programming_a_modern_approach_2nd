#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MSG_LEN 80

bool is_palindrome(const char *message);

int main() {
  char message[MSG_LEN + 1];
  printf("Enter the message: ");
  fgets(message, sizeof(message), stdin);

  if (is_palindrome(message))
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");

  return 0;
}

bool is_palindrome(const char *message) {
  const char *head = message, *tail = message + strlen(message) - 1;

  bool equal = true;
  while (head < tail) {

    while (!isalpha(*head))
      head++;
    while (!isalpha(*tail))
      tail--;

    if (tolower(*head) != tolower(*tail)) {
      equal = false;
      break;
    }
    head++;
    tail--;
  }

  return equal;
}

// test: He lived as a devil, eh!
// test: madam, I am Adam.