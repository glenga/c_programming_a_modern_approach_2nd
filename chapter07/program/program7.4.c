#include <stdio.h>

int main() {
  printf("Enter phone number: ");

  char ch;
  while ((ch = getchar()) != '\n') {
    switch (ch) {
    case 'A':
    case 'B':
    case 'C':
      printf("2");
      break;
    case 'D':
    case 'E':
    case 'F':
      printf("3");
      break;
    case 'G':
    case 'H':
    case 'I':
      printf("4");
      break;
    case 'J':
    case 'K':
    case 'L':
      printf("5");
      break;
    case 'M':
    case 'N':
    case 'O':
      printf("6");
      break;
    case 'P':
    case 'R':
    case 'S':
      printf("7");
      break;
    case 'T':
    case 'U':
    case 'V':
      printf("8");
      break;
    case 'W':
    case 'X':
    case 'Y':
      printf("9");
      break;
    default:
      printf("%c", ch);
      break;
    }
  }

  printf("\n");
  return 0;
}

// Enter phone number: CALLATT
// Enter phone number: 1-800-COL-LECT