#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define COUNT 10000000L

long counter = 0;
// 互斥体是一个联合类型
mtx_t mtx;

void incFunc(void);
void decFunc(void);

int main(void) {
  clock_t c1 = clock();
  thrd_t th1, th2;

  // 初始化互斥体
  if (mtx_init(&mtx, mtx_plain) != thrd_success) {
    fprintf(stderr, "Error initializing the mutex!\n");
    return -1;
  }

  if (thrd_create(&th1, (thrd_start_t)incFunc, NULL) != thrd_success ||
      thrd_create(&th2, (thrd_start_t)decFunc, NULL) != thrd_success) {
    fprintf(stderr, "Error createing thread\n");
    return -1;
  }

  // 两个线程同时修改一个数据，th1加1， th2减1， 最终结果为0
  thrd_join(th1, NULL);
  thrd_join(th2, NULL);

  printf("Counter: %ld\t", counter);
  printf("CPU time %ld ms\n", (clock() - c1) * 1000L / CLOCKS_PER_SEC);

  return 0;
}

// 使用互斥避免数据竞争
void incFunc(void) {
  for (long i = 0; i < COUNT; i++) {
    mtx_lock(&mtx); // 修改数据前加锁
    counter++;
    mtx_unlock(&mtx); // 修改完成及时释放锁
  }
}

void decFunc(void) {
  for (long i = 0; i < COUNT; i++) {
    mtx_lock(&mtx);
    counter--;
    mtx_unlock(&mtx);
  }
}