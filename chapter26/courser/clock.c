#include <stdio.h>
#include <time.h>

int main() {
  clock_t start_clock = clock();
  int i = __INT_MAX__;
  while (i <= 0) {
    i--;
  }
  printf("Processor time used: %ld sec.\n",
         (clock() - start_clock) / CLOCKS_PER_SEC);

  return 0;
}