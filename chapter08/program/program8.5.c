#include <stdio.h>

#define INITAL_BALANCE 100.00
#define NUM_RATERS ((int)(sizeof(values) / sizeof(values[0])))

int main() {
  int rate, years;
  printf("Enter interest rate: ");
  scanf("%d", &rate);
  printf("Enter number of years: ");
  scanf("%d", &years);

  double values[5] = {0};

  printf("\nyears ");
  for (int i = 0; i < NUM_RATERS; i++) {
    values[i] = INITAL_BALANCE;
    printf("%7d%%", rate + i);
  }

  printf("\n");

  for (int year = 1; year <= years; year++) {
    printf("%3d     ", year);
    for (int i = 0; i < NUM_RATERS; i++) {
      for (int month = 1; month <= 12; month++)
        values[i] *= (double)(rate + i) / 12.0 / 100.0 + 1.0;
      printf("%8.2f", values[i]);
    }

    printf("\n");
  }

  return 0;
}

// Enter interest rate: 6
// Enter number of years: 5