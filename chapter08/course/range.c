#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_INT(a, b) (rand() % (b - a) + a)
#define RANGE_FLOAT(a, b) (rand() * 1.0 / (RAND_MAX + 1) * (b - a) + a)

// 1. 生成整数随机数，a b均为整数，且

//    [a,b）---rand()%(b-a)+a

//    [a,b]  ---rand()%(b-a+1)+a

//    (a,b)  ---rand()%(b-a-1)+a+1

//   （a,b]  ---rand()%(b-a)+a+1

// 2. 生成浮点数随机数，a b为整数或浮点数，且a

//   [0,1]---rand()*1.0/RAND_MAX

//   [a,b]---rand()*1.0/RAND_MAX*(b-a)+a

//   [a,b)---rand()*1.0/(RAND_MAX+1)*(b-a)+a

//   (a,b]---(rand()+1)*1.0/(RAND_MAX+1)*(b-a)+a

//   (a,b)---(rand()+1)*1.0/(RAND_MAX+2)*(b-a)+a

int main() {
  srand((unsigned)time(NULL));

  printf("%d\n", RANG_INT(1, 100));
  printf("%.2f", RANG_FLOAT(1.0f, 100.0f));


  return 0;
}