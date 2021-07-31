#include <stdio.h>

int main(void) {
  float num, max = .0f;
  do {
    printf("Enter a number: ");
    scanf("%f", &num);

    if (num > max)
      max = num;

  } while (num > 0);

  printf("The largest number entered was %.2f", max);

  return 0;
}

// Enter a number: 60
// Enter a number: 38.3
// Enter a number: 4.89
// Enter a number: 100.62
// Enter a number: 75.2295
// Enter a number: 0