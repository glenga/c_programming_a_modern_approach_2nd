#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SHIFT 100 // 最多100班次
int flight[2][MAX_SHIFT];

int read_line(char str[], int n, FILE *fp);
int flight_amount(FILE *fp);
void print(int departure, int arrival);

int main(int argc, char *argv[]) {
  if (2 != argc) {
    fprintf(stderr, "Error: missing file name.\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;

  if (NULL == (fp = fopen(argv[1], "r"))) {
    fprintf(stderr, "error open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  int hour, minute, departure_time, arrival_time;
  int amount = flight_amount(fp);

  printf("Enter a 24-hour time: ");
  scanf("%d :%d", &hour, &minute);

  int time = hour * 60 + minute;

  int smallest_diff = abs(flight[0][0] - time);
  for (int i = 1; i < amount; i++) {
    if (abs(flight[0][i] - time) < smallest_diff) {
      smallest_diff = abs(flight[0][i] - time);
      departure_time = flight[0][i];
      arrival_time = flight[1][i];
    }
  }

  print(departure_time, arrival_time);

  fclose(fp);
  return 0;
}

int flight_amount(FILE *fp) {
  int departure_hour, departure_minute, arrival_hour, arrival_minute, i = 1;
  char buff[255];
  while (0 != read_line(buff, 255, fp)) {
    sscanf(buff, "%d%*[:]%d%d%*[:]%d", &departure_hour, &departure_minute,
           &arrival_hour, &arrival_minute);

    // printf("%.2d:%.2d %.2d:%.2d\n", departure_hour, departure_minute,
    //  arrival_hour, arrival_minute);
    flight[0][i] = departure_hour * 60 + departure_minute;
    flight[1][i] = arrival_hour * 60 + arrival_minute;
    i++;
  }
  return i;
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

int read_line(char str[], int n, FILE *fp) {
  int ch, i = 0;

  while (isspace(ch = getc(fp)))
    ;

  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;

    ch = getc(fp);
  }

  str[i] = '\0';

  return i;
}

// test: .\program22.13.exe .\flights.dat