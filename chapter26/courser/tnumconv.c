#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define CHK_VOLID                                                              \
  printf("     %s            %s\n", errno != ERANGE ? "YES" : "NO",            \
         *ptr == '\0' ? "YES" : "NO");

int main(int argc, char *argv[]) {
  char *ptr;
  if (2 != argc) {
    printf("usage: %s string\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  printf("Function  Return Value\n");
  printf("--------  ------------\n");
  printf("atof      %g\n", atof(argv[1]));
  printf("atoi      %d\n", atoi(argv[1]));
  printf("atol      %ld\n", atol(argv[1]));

  printf("Function  Retrun Value      Valid?    String Consumed?\n");
  printf("--------  ------------      ------    ----------------\n");

  errno = 0;
  printf("strtod      %-12g", strtod(argv[1], &ptr));
  CHK_VOLID;

  errno = 0;
  printf("strtod      %-12ld", strtol(argv[1], &ptr, 10));
  CHK_VOLID;

  errno = 0;
  printf("strtod      %-12lu", strtoul(argv[1], &ptr, 10));
  CHK_VOLID;

  return 0;
}

// test: .\tnumconv.exe 3000000