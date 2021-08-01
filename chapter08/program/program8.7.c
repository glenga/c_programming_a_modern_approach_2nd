#include <stdio.h>

#define ROWS 5
#define COLS 5

int main() {
  int array[ROWS][COLS];

  for (int row = 0; row < ROWS; row++) {
    printf("Enter row %d: ", row + 1);
    for (int col = 0; col < COLS; col++) {
      scanf("%d", &array[row][col]);
    }
  }

  int sum;

  printf("Row totals\t: ");
  for (int row = 0; row < ROWS; row++) {
    sum = 0;
    for (int col = 0; col < COLS; col++) {
      sum += array[row][col];
    }
    printf("%-4d", sum);
  }

  printf("\n");

  printf("Column totals\t: ");
  for (int col = 0; col < COLS; col++) {
    sum = 0;
    for (int row = 0; row < ROWS; row++) {
      sum += array[row][col];
    }
    printf("%-4d", sum);
  }

  printf("\n");

  return 0;
}

// Enter row 1: 8 3 9 0 10
// Enter row 2: 3 5 17 1 1
// Enter row 3: 2 8 6 23 1 
// Enter row 4: 15 7 3 2 9
// Enter row 5: 6 14 2 6 0