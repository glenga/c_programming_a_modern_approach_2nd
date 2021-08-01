#include <stdio.h>

void split_date(int day_of_year, int year, int *month, int *day);

int main() {

  int day_of_year, year, month, day;

  printf("enter the year and the day of year: ");
  scanf("%d%d", &year, &day_of_year);

  split_date(day_of_year, year, &month, &day);

  printf("The %d day of %d is %d/%d\n", day_of_year, year, month, day);

  return 0;
}

void split_date(int day_of_year, int year, int *month, int *day) {
  int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if ((year % 4 == 0 && year % 100) || year % 400 == 0)
    days_in_month[2] = 29;

  *month = 1;
  for (int i = 1; i <= 12; i++) {
    if (day_of_year > days_in_month[i]) {
      day_of_year -= days_in_month[i];
      // *month++;
      ++*month;
    } else {
      *day = day_of_year;
      break;
    }
  }
}

// enter the year and the day of year: 2021 365