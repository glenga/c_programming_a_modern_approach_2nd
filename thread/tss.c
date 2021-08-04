#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

tss_t key; // 用于tss指针的全局建

int thrd_Func(void *);   // 线程函数
void destructor(void *); // tss析构函数

int main() {
  thrd_t th1, th2;
  int result1 = 0, result2 = 0;

  if (tss_create(&key, destructor) != thrd_success)
    return -1;

  // 简单的通过线程参数传递一个字符串
  if (thrd_create(&th1, thrd_Func, "Thread_1") != thrd_success ||
      thrd_create(&th2, thrd_Func, "Thread_2") != thrd_success)
    return -2;

  thrd_join(th1, &result1);
  thrd_join(th2, &result2);

  if (result1 != 0 || result2 != 0)
    fputs("Thread error!\n", stderr);
  else
    fputs("Thread finished without error.\n", stdout);

  tss_delete(key); // 释放tss指针所有资源会调用自定义的析构函数

  return 0;
}

// 线程函数， 处理接受的参数
int thrd_Func(void *arg) {
  char *name = (char *)arg;
  size_t size = strlen(name) + 1;

  if (tss_set(key, malloc(size)) != thrd_success)
    return -1;

  // 通过tss_set设置参数，tss_get获取参数
  strcpy((char *)tss_get(key), name);
  printf("print: %s\n", (char *)tss_get(key));

  return 0;
}

// 析构函数
void destructor(void *data) {
  printf("Destructor for %s\n", (char *)data);
  free(data);
}