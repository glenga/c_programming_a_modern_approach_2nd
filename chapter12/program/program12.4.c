#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

bool palindrome_check(char array[], int n);

int main() {
  char array[N];
  char ch;
  int n = 0;

  printf("Enter the message: ");
  while ((ch = getchar()) != '\n') {
    if (ispunct(ch) || isspace(ch))
      continue;

    ch = toupper(ch);

    if (n < N) {
      array[n] = ch;
      n++;
    } else {
      printf("out of range!!\n");
      break;
    }
  }

  if (palindrome_check(array, n))
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");

  return 0;
}

bool palindrome_check(char array[], int n) {
  char *head = array, *tail = array + n - 1;
  bool equal = true;
  while (head++ < tail--) {
    if (*head != *tail) {
      equal = false;
      break;
    }
  }

  return equal;
}

// test: He lived as a devil, eh!
// test: madam, I am Adam.