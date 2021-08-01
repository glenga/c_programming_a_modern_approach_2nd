#include <stdio.h>
#include <string.h>

#define LEN_FILE_NAME 80
#define LEN_FILE_EXTENSION 10

void get_extension(const char *file_name, char *extension);

int main() {
  char file_name[LEN_FILE_EXTENSION + 1];
  char extension[LEN_FILE_EXTENSION + 1];

  printf("Enter a filename with extension: ");
  scanf("%s", file_name);

  get_extension(file_name, extension);

  printf("The extension of file is: %s", extension);

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

// test: hello
// test: hello.txt
// test: hello.txt.txt
