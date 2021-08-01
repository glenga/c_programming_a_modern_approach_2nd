#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
int gcd(int, int);

int main(void) {
    int numerator, denominator;

    printf("Enter a fraction: ");
    scanf("%d /%d", &numerator, &denominator);

    reduce(numerator, denominator, &numerator, &denominator);

    printf("In lowest terms: %d/%d\n", numerator, denominator);

    return 0;
}

int gcd(int m, int n) {
    int tmp;

    if (n == 0) return m;

    tmp = m % n;
    m = n;
    n = tmp;

    return gcd(m, n);
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    int cd = gcd(numerator, denominator);

    *reduced_numerator = numerator / cd;
    *reduced_denominator = denominator / cd;
}

// Enter a fraction: 12/24