#include <stdio.h>
#include <time.h>

#define SEC_OF_DAY (60 * 60 * 24)

int main() {
  struct tm t1, t2;

  t1.tm_sec = 0;
  t1.tm_min = 0;
  t1.tm_hour = 0;

  t2 = t1; // 结构体支持直接赋值

  printf("Enter date1 (mon/day/year): ");
  scanf("%d%*[ -/]%d%*[ -/]%d", &t1.tm_mon, &t1.tm_mday, &t1.tm_year);
  t1.tm_mon--;
  t1.tm_year -= 1900;

  printf("Enter date2 (mon/day/year): ");
  scanf("%d%*[ -/]%d%*[ -/]%d", &t2.tm_mon, &t2.tm_mday, &t2.tm_year);
  t2.tm_mon--;
  t2.tm_year -= 1900;

  printf("Days between dates: %d\n",
         (int)(difftime(mktime(&t2), mktime(&t1)) / SEC_OF_DAY));

  return 0;
}