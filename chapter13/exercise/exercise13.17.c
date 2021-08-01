#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define LEN_FILE_NAME 80
#define LEN_FILE_EXTENSION 10

void get_extension(const char *file_name, char *extension);
bool test_extension(const char *file_name, const char *extension);

int main() {
  char file_name[LEN_FILE_NAME + 1];
  char extension[LEN_FILE_EXTENSION + 1];

  printf("Enter a filename with extension: ");
  scanf("%s%s", file_name, extension);

  if (test_extension(file_name, extension))
    printf("The same extension.\n");
  else
    printf("Different extension.\n");

  return 0;
}

void get_extension(const char *file_name, char *extension) {
  int n = strlen(file_name);
  const char *tail = file_name + n;

  while (n-- >= 0) {
    if (*tail == '.') {
      strcpy(extension, tail + 1);
      return;
    }
    tail--;
  }
  strcpy(extension, "");
}

bool test_extension(const char *file_name, const char *extension) {
  char file_extension[LEN_FILE_EXTENSION];
  get_extension(file_name, file_extension);

  char *p = file_extension;

  while (toupper(*p++) == toupper(*extension++)) {
    if (*p == '\0' && *extension == '\0')
      return true;
  }

  return false;
}

// test: hello txt
// test: hello.txt1  TXT
// test: hello.txt.txt  Txt
// test: hello.txt.md  Txt
