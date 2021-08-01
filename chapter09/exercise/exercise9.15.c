#include <stdio.h>

// double swap(double a, double b);
double median(double x, double y, double z);

int main() {
  double x = 3434.234;
  double y = 4534.2;
  double z = 23.34;

  printf("The median is : %f", median(x, y, z));

  return 0;
}

// double swap(double a, double b) {
//   double temp;
//   temp = a;
//   a = b;
//   b = temp;
// }

double median(double x, double y, double z) {
    double result = x;
    if ((x <= y && y <= z) || (z <= y && y <= x)) result = y;
    else if ((x <= z && z <= y) || (y <= z && z <= x)) result = z;

    return result;    
}