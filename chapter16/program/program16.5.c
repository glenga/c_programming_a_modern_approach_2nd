#include <math.h>
#include <stdio.h>

#define ARRAY_LEN(x) ((int)(sizeof(x) / sizeof(x[0])))

typedef struct {
  int departure;
  int arrival;
} flight;

int main() {
  flight times[] = {{480, 616}, {583, 712},  {679, 811},   {767, 900},
                    {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}};

  int i = 0, user_time, hour, minute;

  printf("Enter a 24-hour time: ");
  scanf("%d :%d", &hour, &minute);
  user_time = hour * 60 + minute;

  while (times[i].departure < user_time)
    i++;

  if (i >= 1 && abs(user_time - times[i - 1].departure) <
                    abs(user_time - times[i].departure))
    i -= 1;

  printf("Closest departure time is ");
  printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n", 
          times[i].departure/60 > 12 ? times[i].departure/60 - 12 : times[i].departure/60,
          times[i].departure%60, times[i].departure > 719 ? 'p' : 'a', 
          times[i].arrival/60 > 12 ? times[i].arrival/60 - 12 : times[i].arrival/60,
          times[i].arrival%60, times[i].arrival > 719 ? 'p' : 'a');
  return 0;
}

// Enter a 24-hour time: 13:15