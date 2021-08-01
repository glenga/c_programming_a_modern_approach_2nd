#include <stdio.h>

union ft {
  float value;
  struct float_value {
    unsigned int fraction : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } zone;
};

int main() {
  union ft f;
  f.zone.sign = 1;
  f.zone.exponent = 128;
  f.zone.fraction = 0;

  printf("%.1f\n", f.value);

  return 0;
}