#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define COUNT 10000000L

// 仅仅申明会引起数据竞争的对象为原子类型即可避免数据竞争
atomic_long counter = 0;

void incFunc(void);
void decFunc(void);

int main(void) {
  clock_t c1 = clock();
  thrd_t th1, th2;

  if (thrd_create(&th1, (thrd_start_t)incFunc, NULL) != thrd_success ||
      thrd_create(&th2, (thrd_start_t)decFunc, NULL) != thrd_success) {
    fprintf(stderr, "Error createing thread\n");
    return -1;
  }

  // 两个线程同时修改一个数据，会引起数据竞争条件，结果是未知的
  thrd_join(th1, NULL);
  thrd_join(th2, NULL);

  printf("Counter: %ld\t", counter);
  printf("CPU time %ld ms\n", (clock() - c1) * 1000L / CLOCKS_PER_SEC);

  return 0;
}

void incFunc(void) {
  for (long i = 0; i < COUNT; i++)
    counter++;
}

void decFunc(void) {
  for (long i = 0; i < COUNT; i++)
    counter--;
}