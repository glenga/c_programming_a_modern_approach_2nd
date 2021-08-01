#include <math.h>
#include <stdio.h>

#define HB0 (8 * 60)
#define HB_TO0 (10 * 60 + 16)
#define HB1 (9 * 60 + 43)
#define HB_TO1 (11 * 60 + 52)
#define HB2 (11 * 60 + 19)
#define HB_TO2 (13 * 60 + 31)
#define HB3 (12 * 60 + 47)
#define HB_TO3 (15 * 60)
#define HB4 (14 * 60)
#define HB_TO4 (16 * 60 + 8)
#define HB5 (15 * 60 + 45)
#define HB_TO5 (17 * 60 + 55)
#define HB6 (19 * 60)
#define HB_TO6 (21 * 60 + 20)
#define HB7 (21 * 60 + 45)
#define HB_TO7 (23 * 60 + 58)

#define SIZE ((int)(sizeof(HB) / sizeof(HB[0])))

int main(void) {

  const int HB[] = {HB0, HB1, HB2, HB3, HB4, HB5, HB6, HB7};
  const int HB_TO[] = {HB_TO0, HB_TO1, HB_TO2, HB_TO3,
                       HB_TO4, HB_TO5, HB_TO6, HB_TO7};

  int hour, minute, i = 0;

  printf("Enter a 24-hour time: ");
  scanf("%d :%d", &hour, &minute);

  int time = hour * 60 + minute;

  while (HB[i] < time)
    i++;

  if (i >= 1 && abs(time - HB[i - 1]) < abs(time - HB[i]))
    i = i - 1;

  printf("最近的航班起飞时间是:%d:%02d, 到达的时间是:%d:%02d.\n", HB[i] / 60,
         HB[i] % 60, HB_TO[i] / 60, HB_TO[i] % 60);

  return 0;
}

// Enter a 24-hour time: 13:15