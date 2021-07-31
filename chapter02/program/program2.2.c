#include <stdio.h>

#define SCALE_FACTOR (4.0f / 3.0f) // 转换因子
#define PI 3.1415926f

int main(void) {
  float r = 10.0f, volume;

  volume = r * r * r * PI * SCALE_FACTOR;

  printf("the volume of the ball with %.2f is: %.2f\n", r, volume);

  return 0;
}