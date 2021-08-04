#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define NP 2 // 生产者数量
#define NC 1 // 消费者数量

int producer(void *); // 线程回调函数
int consumer(void *);

// 线程函数的参数, 每个线程包含一个id及一个线程缓冲区指针
struct Arg {
  int id;
  Buffer bufPtr;
};

_Noreturn void errorExit(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(0xff);
}

int main(void) {
  printf("Producer-Consumer Demo\n\n");
  Buffer buf;
  bufInit(&buf, 5); // 环形队列能存放5个消费品

  // 每个参与者单独一个线程
  thrd_t prod[NP], cons[NC];
  // 每个线程对应一个id，共用一个环形缓冲区
  struct Arg prodArg[NP], consArg[NC];

  int i = 0, res = 0;

  // 启用生产者同时生产
  for (i = 0; i < NP; i++) {
    prodArg[i].id = i + 1;
    prodArg[i].bufPtr = buf;
    if (thrd_create(&prod[i], producer, &prodArg[i]) != thrd_success)
      errorExit("Thread error.");
  }

  // 启用消费者同时消费
  for (i = 0; i < NC; i++) {
    consArg[i].id = i + 1;
    consArg[i].bufPtr = buf;
    if (thrd_create(&cons[i], consumer, &consArg[i]) != thrd_success)
      errorExit("Thread error.");
  }

  // 等待生产者线程结束
  for (i = 0; i < NP; i++) {
    thrd_join(prod[i], &res);
    printf("\nProducer %d ended with result %d.\n", prodArg[i].id, res);
  }

  // 等待消费者线程结束
  for (i = 0; i < NC; i++) {
    thrd_join(cons[i], &res);
    printf("\nConsumer %d ended with result %d.\n", consArg[i].id, res);
  }

  bufDestory(&buf);

  return 0;
}

int producer(void *parm) {
  struct Arg *argPtr = (struct Arg *)parm;
  int id = argPtr->id;
  Buffer bufPtr = argPtr->bufPtr;

  int count = 0;
  for (int i = 0; i < 10; i++) { // 每个生产者生产10个
    int data = id * 10000 + i;   // 每个生产者有自己的数据编号
    if (bufPut(bufPtr, data)) {
      printf("Producer %d produced %d\n", id, data);
      count++;
    } else {
      fprintf(stderr, "Producer %d: error storing %d.\n", id, data);
      return -id;
    }
  }
  return count;
}

// 消费者线程
int consumer(void *parm) {
  struct Arg *argPtr = (struct Arg *)parm;
  int id = argPtr->id;
  Buffer bufPtr = argPtr->bufPtr;

  int data = 0;
  int count = 0;
  while (bufGet(bufPtr, &data, 1)) {
    count++;
    printf("Consumer %d consumed %d\n", id, data);
  }
  return count;
}

// gcc -o a.o buffer.c product_consumer.c -pthread
// 这个程序有个bug,当消费者数量大于1时，
// 生产者已经退出，没有退出的消费者会一直等待唤醒