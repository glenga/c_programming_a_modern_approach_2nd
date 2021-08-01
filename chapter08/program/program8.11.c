#include <stdio.h>

int main() {
  char array[100] = {0};
  int n = 0;

  printf("Enter phone number: ");

  char ch;
  while ((ch = getchar()) != '\n') {
    switch (ch) {
    case 'A':
    case 'B':
    case 'C':
      array[n++] = '2';
      break;
    case 'D':
    case 'E':
    case 'F':
      array[n++] = '3';
      break;
    case 'G':
    case 'H':
    case 'I':
      array[n++] = '4';
      break;
    case 'J':
    case 'K':
    case 'L':
      array[n++] = '5';
      break;
    case 'M':
    case 'N':
    case 'O':
      array[n++] = '6';
      break;
    case 'P':
    case 'R':
    case 'S':
      array[n++] = '7';
      break;
    case 'T':
    case 'U':
    case 'V':
      array[n++] = '8';
      break;
    case 'W':
    case 'X':
    case 'Y':
      array[n++] = '9';
      break;
    default:
      array[n++] = ch;
      break;
    }
  }

  printf("In numeric form: ");

  for (int i = 0; i < n; i++)
    printf("%c", array[i]);

  printf("\n");
  return 0;
}

// Enter phone number: 1-800-COL-LECT