#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int month, day, year, total = 0;
  int min_month, min_day, min_year;
  int min_total = __INT_MAX__; // 初始化为int的最大值

  while (true) {
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month, &day, &year);
    total = month * 30 + day + year * 365;

    if (total == 0)
      break;

    if (total < min_total) {
      min_day = day;
      min_month = month;
      min_year = year;
      min_total = total;
    }
  }

  printf("%d/%d/%.2d is the earliest date.\n", min_month, min_day, min_year);

  return 0;
}

// Enter a date (mm/dd/yy): 3/6/08
// Enter a date (mm/dd/yy): 5/17/07
// Enter a date (mm/dd/yy): 6/3/07
// Enter a date (mm/dd/yy): 0/0/0
// 5/17/07 is the earliest date.