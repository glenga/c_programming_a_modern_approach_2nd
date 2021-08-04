/* 在几个并行线程中计算数组元素的和 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <time.h>

#define MAX_THREADS 4      // 线程数
#define MIN_BLOCK_SIZE 100 // 一个数组块的最小值

#define ARRAY_LEN 100000

typedef struct {
  double *start;  // 传递给parallel_sum()的数组块的起始地址
  int len;        // 数组块长度
  int block_size; // 最小数组块的大小
  double sum;     // 求和结果
} sum_arg;

int parallel_sum(void *arg); // 线程回调函数，thrd_start_t类型
bool sum(double arr[], int len, double *sumPtr);

int main() {
  double a[ARRAY_LEN];
  double sum_array;

  srand(time(NULL));

  for (int i = 0; i < ARRAY_LEN; i++)
    a[i] = rand() / (double)(RAND_MAX) + 1000;

  if (sum(a, ARRAY_LEN, &sum_array))
    printf("The array sum: %.2lf\n", sum_array);
  else
    printf("error!\n");

  return 0;
}

// 计算数组元素的和，并写入*sumptr
bool sum(double arr[], int len, double *sumptr) {
  // 将数组平分给每个线程
  int block_size = len / MAX_THREADS;
  if (block_size < MIN_BLOCK_SIZE)
    block_size = len;

  sum_arg args = {arr, len, block_size, 0.0};

  if (parallel_sum(&args)) {
    *sumptr += args.sum;
    return true;
  } else
    return false;
}

// 线程回调函数
int parallel_sum(void *arg) {
  sum_arg *argp = (sum_arg *)arg;
  // 如果长度小于块大小，对所有元素求和
  if (argp->len <= argp->block_size) {
    for (int i = 0; i < argp->len; i++)
      argp->sum += argp->start[i];

    return 1;
  } else { // 长度大于块, 分解
    int mid = argp->len / 2;
    // 后半个数组
    sum_arg arg2 = {argp->start + mid, argp->len - mid, argp->block_size, 0};
    // 修改前半长度
    argp->len = mid;

    thrd_t th;
    int res = 0;
    // 新线程中处理前半个数组le
    if (thrd_create(&th, parallel_sum, arg) != thrd_success)
      return 0;

    // 当前线程递归处理后半个数组
    if (!parallel_sum(&arg2)) {
      thrd_detach(th);
      return 0;
    }

    // 等待线程执行完成返回,返回状态在res中
    thrd_join(th, &res);
    if (!res)
      return 0;

    argp->sum += arg2.sum;
    return 1;
  }
}

// gcc -o parallel_sum parallel_sum.c -pthread