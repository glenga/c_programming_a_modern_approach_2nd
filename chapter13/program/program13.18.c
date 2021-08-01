#include <stdio.h>

int main() {
  const char *months[] = {
      "",     "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};

  int month, day, year;

  printf("Enter a date(mm/dd/yyyy): ");
  scanf("%d /%d /%d", &month, &day, &year);

  printf("You entered the date %s %d, %d", months[month], day, year);
  return 0;
}


// test:  2/17/2011