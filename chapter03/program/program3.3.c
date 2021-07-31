#include <stdio.h>

int main(void) {
  int prefix, identifier, publisher, number, check;
  printf("Enter ISBN: ");
  scanf("%d -%d -%d -%d -%d", &prefix, &identifier, &publisher, &number,
        &check);
  printf("GS1 prefix: %d\n", prefix);
  printf("Group identifier: %d\n", identifier);
  printf("Publisher code: %d\n", publisher);
  printf("Item number: %d\n", number);
  printf("Check digit: %d\n", check);
  return 0;
}

// Enter ISBN: 987-0-393-9750-3