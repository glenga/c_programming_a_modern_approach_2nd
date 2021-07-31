#include <stdio.h>

int main(void) {
  int hour, min;
  printf("Enter a 24-hour time (xx:xx): ");
  scanf("%d :%d", &hour, &min);

  printf("Equivate 12-hour time: ");

  if (hour > 12)
    printf("%2d:%2d PM\n", hour - 12, min);
  else
    printf("%2d:%2d AM\n", hour, min);

  return 0;
}

// Enter a 24-hour time (xx:xx): 21:11