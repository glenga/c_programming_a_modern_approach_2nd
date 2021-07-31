#include <stdio.h>

int main(void) {
  float money;

  printf("Enter an amount: ");
  scanf("%f", &money);

  printf("With tax added: $%.2f", money * (1.0f + 5.0f / 100.0f));
  return 0;
}