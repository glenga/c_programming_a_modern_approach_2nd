#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define EP 0.00001

int main() {
  double x, y = 1.0, new_y;

  printf("Enter a positive number: ");
  scanf("%lf", &x);

  while (true) {
    new_y = (y + x / y) / 2;
    
    if (fabs(new_y - y) < EP * y)
      break;
    else
      y = new_y;
  }

  printf("Square root: %lf\n", y);

  return 0;
}

// Enter a positive number: 3