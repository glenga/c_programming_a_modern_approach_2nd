#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

void str_toupper(const char *str, char *str_out);

int main(int argc, char *argv[]) {
  const char *planets[] = {"Mercury", "Venus",  "Earth",   "Mars", "Jupiter",
                           "Saturn",  "Uranus", "Neptune", "Pluto"};

  int i, j;
  char buff_argv[50];
  char buff_planets[50];

  for (i = 1; i < argc; i++) {
    str_toupper(argv[i], buff_argv);
    for (j = 0; j < NUM_PLANETS; j++) {
      str_toupper(planets[j], buff_planets);

      if (strcmp(buff_argv, buff_planets) == 0) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    }

    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }

  return 0;
}

void str_toupper(const char *str, char *str_out) {
  while (*str++)
    *str_out++ = toupper(*str);

  *str_out = '\0';
}

// test: .\chapter13\program\program13.6.exe jupiter venus earth fred MARS