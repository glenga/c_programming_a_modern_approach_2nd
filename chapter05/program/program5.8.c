#include <stdio.h>

#define HB1 (8 * 60 + 0)
#define HB2 (9 * 60 + 43)
#define HB3 (11 * 60 + 19)
#define HB4 (12 * 60 + 47)
#define HB5 (14 * 60 + 0)
#define HB6 (15 * 60 + 45)
#define HB7 (19 * 60 + 0)
#define HB8 (21 * 60 + 45)

#define MID_TIME(m1, m2) (m1 + (m2 - m1) / 2)

int main(void) {

  int time, minute;

  printf("Enter a 24-hour time: ");
  scanf("%d :%d", &time, &minute);

  int minutes_after_0 = time * 60 + minute;

  if (minutes_after_0 <= MID_TIME(HB2, HB1)) {
    printf("Closest departure time is 8:00 a.m. arriving at 10:16 a.m.\n");
  } else if (minutes_after_0 <= MID_TIME(HB3, HB2)) {
    printf("Closest departure time is 9:43 p.m. arriving at 11:52 a.m.\n");
  } else if (minutes_after_0 <= MID_TIME(HB4, HB3)) {
    printf("Closest departure time is 11:19 p.m. arriving at 1:31 p.m.\n");
  } else if (minutes_after_0 <= MID_TIME(HB5, HB4)) {
    printf("Closest departure time is 12:47 p.m. arriving at 3:00 p.m.\n");
  } else if (minutes_after_0 <= MID_TIME(HB6, HB5)) {
    printf("Closest departure time is 2:00 p.m. arriving at 4:08 p.m.\n");
  } else if (minutes_after_0 <= MID_TIME(HB7, HB6)) {
    printf("Closest departure time is 3:45 p.m. arriving at 5:55 p.m.\n");
  } else if (minutes_after_0 <= MID_TIME(HB8, HB7)) {
    printf("Closest departure time is 7:00 p.m. arriving at 9:20 p.m.\n");
  } else
    printf("Closest departure time is 9:45 p.m. arriving at 11:58 p.m.\n");

  return 0;
}

// Enter a 24-hour time: 13:15