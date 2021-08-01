#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i = 0, sum = 0;

  while (i++ < argc)
    sum += atoi(argv[i]);

  printf("Total: %d\n", sum);
}

// test: .\chapter13\program\program13.5.exe 8 24 62