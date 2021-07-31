#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int i, denom;
  float e, epsilon, term;

  // 录入精度0.00001
  printf("Enter epsilon: ");
  scanf("%f", &epsilon);

  for (i = 1, denom = 1, e = 1.0f, term = 1.0f; term > epsilon; i++) {
    term = (1.0f / (denom *= i));
    e += term;
  }
  printf("Approximation of e: %f\n", e);

  return 0;
}

// Enter epsilon: 0.00001