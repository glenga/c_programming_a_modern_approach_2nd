#include <stdbool.h>
#include <stdio.h>

bool is_leap_year(int year);
int day_of_year(int month, int day, int year);

int main() {
  int year, month, day;
  printf("Enter the date (mm/dd/yy): ");
  scanf("%d /%d /%d", &month, &day, &year);
  printf("The date is %d day of year.\n", day_of_year(month, day, year));
}

bool is_leap_year(int year) {
  if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
    return true;
  else
    return false;
}

// 计算日期是一年中的第几天, 为了方便一一对应,下标0控制
int day_of_year(int month, int day, int year) {
  int days_every_month[13] = {0,  31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};
  int sum_day;

  if (is_leap_year(year))
    days_every_month[2] = 29;
  else
    days_every_month[2] = 28;

  for (int i = 1; i < month; i++)
    sum_day += days_every_month[i];

  return sum_day + day;
}