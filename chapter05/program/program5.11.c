#include <stdio.h>

int main(void) {
  int num;
  printf("Enter a two-digit number: ");
  scanf("%2d", &num); // 这里会截断输入的数字
  if (num > 0 && num < 10) {
    switch (num) {
    case 1:
      printf("one\n");
      break;
    case 2:
      printf("two\n");
      break;
    case 3:
      printf("three\n");
      break;
    case 4:
      printf("four\n");
      break;
    case 5:
      printf("five\n");
      break;
    case 6:
      printf("six\n");
      break;
    case 7:
      printf("seven\n");
      break;
    case 8:
      printf("eight\n");
      break;
    case 9:
      printf("nine\n");
      break;
    }
  }

  else if (num > 9 && num < 20) {
    switch (num) {
    case 10:
      printf("ten\n");
      break;
    case 11:
      printf("eleven\n");
      break;
    case 12:
      printf("twelve\n");
      break;
    case 13:
      printf("thirteen\n");
      break;
    case 14:
      printf("fourteen\n");
      break;
    case 15:
      printf("fifteen\n");
      break;
    case 16:
      printf("sixteen\n");
      break;
    case 17:
      printf("seventeen\n");
      break;
    case 18:
      printf("eighteen\n");
      break;
    case 19:
      printf("nineteen\n");
      break;
    }
  } else if (num < 100 && num >= 20) {

    int s = num / 10;
    int g = num % 10;

    switch (s) {
    case 2:
      printf("twenty");
      break;
    case 3:
      printf("thirty");
      break;
    case 4:
      printf("forty");
      break;
    case 5:
      printf("fifty");
      break;
    case 6:
      printf("sixty");
      break;
    case 7:
      printf("seventy");
      break;
    case 8:
      printf("eighty");
      break;
    case 9:
      printf("ninety");
      break;
    }

    switch (g) {
    case 0:
      printf("\n");
      break;
    case 1:
      printf("-one\n");
      break;
    case 2:
      printf("-two\n");
      break;
    case 3:
      printf("-three\n");
      break;
    case 4:
      printf("-four\n");
      break;
    case 5:
      printf("-five\n");
      break;
    case 6:
      printf("-six\n");
      break;
    case 7:
      printf("-seven\n");
      break;
    case 8:
      printf("-eight\n");
      break;
    case 9:
      printf("-nine\n");
      break;
    }
  } else {
    printf("不支持的数字.\n");
  }
  return 0;
}

// Enter a two-digit number: 96