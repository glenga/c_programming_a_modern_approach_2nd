#include <stdio.h>
#include <stdlib.h>

// 航班时间, 第一行与第二行对应,分别为航班的起降时间
const int flight[2][8] = {
    {8 * 60 + 0, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60 + 0,
     15 * 60 + 45, 19 * 60 + 0, 21 * 60 + 45},
    {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60 + 0, 16 * 60 + 8,
     17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58}};

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time);
void print(int departure_time, int arrival_time);

int main(void) {
  int hour, minute, departure_time, arrival_time;

  printf("Enter a 24-hour time: ");
  scanf("%d :%d", &hour, &minute);

  find_closest_flight(hour * 60 + minute, &departure_time, &arrival_time);
  print(departure_time, arrival_time);

  return 0;
}

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time) {
  int smallest_diff = abs(flight[0][0] - desired_time);
  for (int i = 1; i < 8; i++) {
    if (abs(flight[0][i] - desired_time) < smallest_diff) {
      smallest_diff = abs(flight[0][i] - desired_time);
      *departure_time = flight[0][i];
      *arrival_time = flight[1][i];
    }
  }
}

void print(int departure, int arrival) {
  char a_or_p_of_departure = 'a', a_or_p_of_arrival = 'a';
  if (departure >= 12 * 60) {
    a_or_p_of_departure = 'p';
    departure = departure >= 13 * 60 ? departure - 12 * 60 : departure;
  }
  if (arrival >= 12 * 60) {
    a_or_p_of_arrival = 'p';
    arrival = arrival >= 13 * 60 ? arrival - 12 * 60 : arrival;
  }
  printf(
      "Closest departure time is %2d:%.2d %c.m. arriving at %2d:%.2d %c.m.\n",
      departure / 60, departure % 60, a_or_p_of_departure, arrival / 60,
      arrival % 60, a_or_p_of_arrival);
}

// Enter a 24-hour time: 13:15