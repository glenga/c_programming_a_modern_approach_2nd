#include <stdio.h>

int main(void) {
  int numerical;
  printf("Enter numerical grade: ");
  scanf("%d", &numerical);

  if (numerical > 100 || numerical < 0) {
    printf("Error!\n");
    return -1;
  }

  int s = numerical / 10;

  printf("Letter grade: ");
  switch (s) {
  case 10:
  case 9:
    printf("A\n");
    break;
  case 8:
    printf("B\n");
    break;
  case 7:
    printf("C\n");
    break;
  case 6:
    printf("D\n");
    break;
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    printf("E\n");
    break;
  }

  return 0;
}

// Enter numerical grade: 84