#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main() {
  int total_sec, hour, minute, second;

  printf("Enter the total seconds from midnight(0-86400): ");
  scanf("%d", &total_sec);

  split_time(total_sec, &hour, &minute, &second);

  printf("the time is: %2d:%2d:%2d\n", hour, minute, second);

  return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec) {
  *hr = total_sec / (60 * 60);
  total_sec %= (60 * 60);

  *min = total_sec / 60;
  *sec = total_sec % 60;
}

// Enter the total seconds from midnight(0-86400): 86000