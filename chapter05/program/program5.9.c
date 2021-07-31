#include <stdio.h>

int main(void) {

  int d1, d2, m1, m2, y1, y2;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d /%d /%d", &m1, &d1, &y1);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d /%d /%d", &m2, &d2, &y2);

  int day1 = y1 * 365 + m1 * 30 + d1;
  int day2 = y2 * 365 + m2 * 30 + d2;

  if (day1 > day2)
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m1, d1, y1);
  else if (day1 < day2)
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
  else if (day1 == day2)
    printf("%d/%d/%.2d is equal to %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);

  return 0;
}

// Enter first date (mm/dd/yy): 2/11/2011
// Enter second date (mm/dd/yy): 3/23/2011