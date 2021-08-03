#include <ctype.h>
#include <stdio.h>
#include <string.h>

int cmp(char *str1, char *str2);

int main(int argc, char *argv[]) {
  int i, j;
  char *planet[] = {"Mercury", "Venus",  "Earth",   "Mars", "Jupiter",
                    "Saturn",  "Uranus", "Neptune", "Pluto"};

  for (i = 1; i < argc; i++) {
    for (j = 0; j < 9; j++) {
      if (cmp(argv[i], planet[j]) == 0) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
      if (j == 8) {
        printf("%s is not a planet\n", argv[i]);
      }
    }
  }
  return 0;
}

int cmp(char *str1, char *str2) {

  while (tolower(*str1) == tolower(*str2)) {
    if (*str1 == '\0') {
      return 0;
    }
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

// .\planet.exe planet Jupiter Venus Earth Fred