#include <stdio.h>

int main(void) {
  int a, b, c, d;

  printf("Enter 4 Integers: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);

  int largest, smallest;

  largest = a;
  if (b > largest)
    largest = b;
  else if (c > largest)
    largest = c;
  else if (d > largest)
    largest = d;

  printf("Largest: %d\n", largest);

  smallest = a;
  if (b < smallest)
    smallest = b;
  else if (c < smallest)
    smallest = c;
  else if (d < smallest)
    smallest = d;

  printf("Largest: %d\n", smallest);
  return 0;
}

// Enter 4 Integers: 21 43 10 35