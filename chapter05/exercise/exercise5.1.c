#include <stdio.h>

int main(void)
{
    int i = 2, j = 3;
    // 先优先级高的四则运算
    int k = i * j == 6;
    printf("%d\n", k);

    i = 5;
    j = 10;
    k = 1;
    // 相同优先级，从左到右
    printf("%d\n", k > i < j);

    i = 3;
    j = 2;
    k = 1;
    // 相同优先级， 从左到右
    printf("%d\n", i < j == j < k);

    i = 3;
    j = 4;
    k = 5;
    // 先计算优先级高的， 再从左到右
    printf("%d\n", i % j + i < k);

    return 0;
}