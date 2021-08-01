#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANG_INT(a, b) (rand() % (b - a) + a)
#define SIZE ((int)sizeof(ch) / sizeof(ch[0]))

int evaluate_position(char board[8][8]);

int main() {
  const char ch[] = {'K', 'Q', 'R', 'B', 'N', 'P',
                     'k', 'q', 'r', 'b', 'n', 'p'};

  char board[8][8];

  srand((unsigned)time(NULL));

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      board[i][j] = ch[RANG_INT(0, SIZE)];
      printf("%3c", board[i][j]);
    }
    printf("\n");
  }

  if (evaluate_position(board) > 0)
    printf("白棋占优.\n");
  else if (evaluate_position(board) < 0)
    printf("黑棋占优.\n");
  else
    printf("平局.\n");

  return 0;
}

int evaluate_position(char board[8][8]) {

  char *p;
  int white = 0, black = 0;

  for (p = board[0]; p < board[0] + 64; p++) {

    switch (*p) {
    case 'Q':
      white += 9;
      break;
    case 'q':
      black += 9;
      break;
    case 'R':
      white += 5;
      break;
    case 'r':
      black += 5;
      break;
    case 'B':
      white += 3;
      break;
    case 'b':
      black += 3;
      break;
    case 'N':
      white += 3;
      break;
    case 'n':
      black += 3;
      break;
    case 'P':
      white++;
      break;
    case 'p':
      black++;
      break;
    default:
      break;
    }
  }
  return white - black;
}