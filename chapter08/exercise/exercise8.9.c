#include <stdio.h>
#include <stdlib.h> // srand
#include <time.h>

// 生成范围浮点数
#define RANG_FLOAT(a, b) (rand() * 1.0 / (RAND_MAX + 1) * (b - a) + a)
#define DAYS 30
#define HOURS 24

int main() {
  float temperaters[DAYS][HOURS];
  float sum = 0;


  srand((unsigned)time(NULL));

  for (int day = 0; day < DAYS; day++) {
    for (int hour = 0; hour < 24; hour++) {
      temperaters[day][hour] = RANG_FLOAT(15.0f, 42.0f);

      sum += temperaters[day][hour];
      printf("%8.2f", temperaters[day][hour]);
    }
    printf("\n");
  }

  printf("\n\n月平均气温: %.2f\n", sum / ((float)DAYS * (float)HOURS));

  return 0;
}