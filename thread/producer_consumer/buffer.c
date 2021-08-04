/*
多线程访问
用于“生产者-消费者”模型的环形缓冲区
*/

#include "buffer.h"
#include <stdlib.h>
#include <threads.h>

struct buf_t {
  int *data;          // 数据数组指针
  size_t size, count; // 数组空间size和已存元素数量count
  size_t tip, tail;   // tip = 下一个空位置索引
  mtx_t mtx;
  cnd_t cndPut, cndGet; // 两个条件变量
};

bool bufInit(Buffer *bufPtr, size_t size) {
  // 先分配bufPtr指向的数据结构需要的空间
  if ((*bufPtr = malloc(sizeof(struct buf_t))) == NULL)
    return false;

  // 动态分配环形缓冲区
  if (((*bufPtr)->data = malloc(size * sizeof(int))) == NULL)
    return false;

  (*bufPtr)->size = size;
  (*bufPtr)->count = 0;
  (*bufPtr)->tip = (*bufPtr)->tail = 0;

  // 初始化互斥体和条件变量
  return mtx_init(&(*bufPtr)->mtx, mtx_plain) == thrd_success &&
         cnd_init(&(*bufPtr)->cndPut) == thrd_success &&
         cnd_init(&(*bufPtr)->cndGet) == thrd_success;
}

void bufDestory(Buffer *bufPtr) {
  cnd_destroy(&(*bufPtr)->cndGet);
  cnd_destroy(&(*bufPtr)->cndPut);
  mtx_destroy(&(*bufPtr)->mtx);
  free((*bufPtr)->data);
  free(*bufPtr);
}

// 在缓冲区中插入一个元素
bool bufPut(Buffer bufPtr, int data) {
  mtx_lock(&bufPtr->mtx); // 操作共享数据先上锁

  // 直到缓冲区已满，创建等待条件
  while (bufPtr->count == bufPtr->size) {
    // 条件设置成功会释放互斥体
    if (cnd_wait(&bufPtr->cndPut, &bufPtr->mtx) != thrd_success)
      return false;
  }
  bufPtr->data[bufPtr->tip] = data;
  bufPtr->tip = (bufPtr->tip + 1) % bufPtr->size;
  ++bufPtr->count;

  mtx_unlock(&bufPtr->mtx); // 解锁数据
  // 唤醒消费者线程
  cnd_signal(&bufPtr->cndGet);
  // cnd_broadcast(&bufPtr->cndGet);
  return true;
}

// 从缓冲区中移除一个元素
bool bufGet(Buffer bufPtr, int *dataPtr, int sec) {
  // 设置等待时间间隔
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  ts.tv_sec += sec;

  mtx_lock(&bufPtr->mtx); // 操作共享数据先上锁

  // 直到缓冲区为空则等待
  while (bufPtr->count == 0) {
    // 条件设置成功会暂时释放互斥体，过了设定时间会自动获得互斥体
    if (cnd_timedwait(&bufPtr->cndGet, &bufPtr->mtx, &ts) != thrd_success)
      return false;
  }

  *dataPtr = bufPtr->data[bufPtr->tail];
  bufPtr->tail = (bufPtr->tail + 1) % bufPtr->size;
  --bufPtr->count;

  mtx_unlock(&bufPtr->mtx); // 解锁数据
  // 唤醒生产者线程
  cnd_signal(&bufPtr->cndPut);

  return true;
}