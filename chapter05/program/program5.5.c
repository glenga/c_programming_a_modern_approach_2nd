#include <stdio.h>

int main(void) {
  float income, tax = 0.0f;

  printf("Enter the income: ");
  scanf("%f", &income);

  if (income < 750)
    tax = income * .01f;
  else if (income < 2250.0f)
    tax = 7.5f + (income - 750.0f) * .02f;
  else if (income < 3750.0f)
    tax = 37.5f + (income - 2250.0f) * .03f;
  else if (income < 5250.0f)
    tax = 82.5f + (income - 3750.0f) * .04f;
  else if (income < 7000.0f)
    tax = 142.5f + (income - 5250.0f) * .05f;
  else
    tax = 2300.0f + (income - 7000.0f) * .06f;

  printf("The tax is: %.2f", tax);

  return 0;
}

// Enter the income: 80000