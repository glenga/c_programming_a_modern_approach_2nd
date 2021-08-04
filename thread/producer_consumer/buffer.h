#include <stdbool.h>
#include <stddef.h>

typedef struct buf_t *Buffer;

bool bufInit(Buffer *bufPtr, size_t size);
void bufDestory(Buffer *bufPtr);

bool bufPut(Buffer bufPtr, int data);
bool bufGet(Buffer bufPtr, int *dataPtr, int sec);