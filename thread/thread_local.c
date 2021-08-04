#include <stdio.h>
#include <threads.h>

thread_local int val = 10; // 线程本地变量

void print_var(void) { printf("var = %d\n", val); }

int func(void *); // 线程回调函数

int main(void) {
  thrd_t th1;
  if (thrd_create(&th1, func, NULL) != thrd_success) {
    fprintf(stderr, "Error creating thread.\n");
    return 0xff;
  }

  print_var();
  thrd_join(th1, NULL);

  print_var();
  return 0;
}

int func(void *arg) {
  val += 10; // 线程本地变量，在线程内时一份拷贝，改变不会影响线程外的值
  printf("---- In thread func---- \n");
  print_var();
  printf("--- End thread func---- \n");
  return 0;
}