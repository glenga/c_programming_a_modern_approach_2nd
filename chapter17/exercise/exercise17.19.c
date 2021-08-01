#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT_CMD ((int)(sizeof(file_cmd) / sizeof(file_cmd[0])))

void new_cmd() { printf("function new_cmd\n"); }

void open_cmd() { printf("function open_cmd\n"); }

void close_cmd() { printf("function close_cmd\n"); }

void close_all_cmd() { printf("function close_all_cmd\n"); }

void save_as_cmd() { printf("function save_as_cmd\n"); }

void save_all_cmd() { printf("function save_all_cmd\n"); }

void print_cmd() { printf("function print_cmd\n"); }

void exit_cmd() { printf("function exit_cmd\n"); }

struct {
  char *cmd_name;
  void (*cmd_pointer)(void);
} file_cmd[] = {{"new", new_cmd},         {"open", open_cmd},
                {"close", close_cmd},     {"close all", close_all_cmd},
                {"save as", save_as_cmd}, {"save all", save_all_cmd},
                {"print", print_cmd},     {"exit", exit_cmd}};

void run_command(char *str) {
  for (int i = 0; i < COUNT_CMD; i++) {
    if (strcmp(str, file_cmd[i].cmd_name) == 0)
      (*file_cmd[i].cmd_pointer)(); // file_cmd[i].cmd_pointer();
  }
}

int main() {
  char *cmd[] = {"new",     "open",     "close", "close all",
                 "save as", "save all", "print", "exit"};

  // 每个命令都试一遍
  for (int i = 0; i < COUNT_CMD; i++)
    run_command(cmd[i]);

  return 0;
}