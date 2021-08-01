#include <stdio.h>

#define N 100

void reversal(char array[], int n);

int main() {
  char array[N];
  char ch;
  int n = 0;

  printf("Enter the message: ");
  while ((ch = getchar()) != '\n') {
    if (n < N) {
      array[n] = ch;
      n++;
    } else {
      printf("out of range!!\n");
      break;
    }
  }

  reversal(array, n);

  // 输出
  printf("Reversal is: ");
  for (char *p = array; p < array + n; p++)
    printf("%c", *p);

  printf("\n");

  return 0;
}

void reversal(char array[], int n) {
  char *head = &array[0], *tail = &array[0] + n - 1;
  char tmp;
  while (head < tail) {
    tmp = *head;
    *head++ = *tail;
    *tail-- = tmp;
  }
}

// test: Don't get mad, get even.