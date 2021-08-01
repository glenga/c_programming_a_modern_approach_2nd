#include <ctype.h>
#include <stdio.h>

//                   0
//                   _        _
//                 5|_|1     |_|
//                 4|_|2     |_|
//                   3
//   // 7 段显示器

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
#define MAX_DIGITS 10
#define DIGIT_WIDTH 4

char digits[3][MAX_DIGITS * DIGIT_WIDTH];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main() {
  char ch;
  int pos = 0;

  clear_digits_array();
  printf("Enter a number: ");
  while ((ch = getchar()) != '\n') {
    if (!isdigit(ch)) {
      continue;
    } else {
      process_digit(ch - '0', pos);
    }

    pos += DIGIT_WIDTH;
  }

  print_digits_array();
  return 0;
}

// 数字处理函数
void process_digit(int digit, int position) {
  //                   0
  //                   _        _
  //                 5|_|1     |_|
  //                 4|_|2     |_|
  //                   3
  //   // 7 段显示器
  if (segments[digit][0] == 1)
    digits[0][position + 1] = '_';

  if (segments[digit][5] == 1)
    digits[1][position + 0] = '|';

  if (segments[digit][6] == 1)
    digits[1][position + 1] = '_';

  if (segments[digit][1] == 1)
    digits[1][position + 2] = '|';

  if (segments[digit][4] == 1)
    digits[2][position + 0] = '|';

  if (segments[digit][3] == 1)
    digits[2][position + 1] = '_';

  if (segments[digit][2] == 1)
    digits[2][position + 2] = '|';
}

// 清空数组
void clear_digits_array(void) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < MAX_DIGITS * DIGIT_WIDTH; j++)
      digits[i][j] = ' ';
  }
}

// print
void print_digits_array(void) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < MAX_DIGITS * DIGIT_WIDTH; j++)
      printf("%c", digits[i][j]);

    printf("\n");
  }
}

// 491-9014