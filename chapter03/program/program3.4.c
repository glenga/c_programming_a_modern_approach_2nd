#include <stdio.h>
int main(void) {
  int a, b, c;
  printf("Enter phone number [(XXX) xxx-xxx]: ");
  scanf(" (%d )%d -%d", &a, &b, &c);
  printf("You entered:%d.%d.%d\n", a, b, c);
  return 0;
}
// Enter phone number [(XXX) xxx-xxx]: (404) 817-6900