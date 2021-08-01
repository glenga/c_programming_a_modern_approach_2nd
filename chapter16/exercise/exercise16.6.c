#include <stdio.h>

struct fraction {
  int numerator;
  int denominator;
};

struct fraction reduce_fraction(struct fraction f);
struct fraction add_fractions(struct fraction f1, struct fraction f2);
struct fraction subtract_fractions(struct fraction f1, struct fraction f2);
struct fraction multiply_fractions(struct fraction f1, struct fraction f2);
struct fraction divide_fractions(struct fraction f1, struct fraction f2);

int main() {

  struct fraction f, f1 = {0, 0}, f2 = {0, 0};
  printf("Enter fraction1 (x/y): ");
  scanf("%d /%d", &f1.numerator, &f1.denominator);
  printf("Enter fraction2 (x/y): ");
  scanf("%d /%d", &f2.numerator, &f2.denominator);

  f = add_fractions(f1, f2);
  printf("f1 + f2 = %d/%d\n", f.numerator, f.denominator);
  f = subtract_fractions(f1, f2);
  printf("f1 - f2 = %d/%d\n", f.numerator, f.denominator);
  f = multiply_fractions(f1, f2);
  printf("f1 * f2 = %d/%d\n", f.numerator, f.denominator);
  f = divide_fractions(f1, f2);
  printf("f1 / f2 = %d/%d\n", f.numerator, f.denominator);

  return 0;
}

// GCD
struct fraction reduce_fraction(struct fraction f) {
  int temp;
  int n = f.numerator, d = f.denominator;

  while (n % d != 0) {
    temp = d;
    d = n % d;
    n = temp;
  }
  f.numerator /= d;
  f.denominator /= d;
  return f;
}

// 加
struct fraction add_fractions(struct fraction f1, struct fraction f2) {
  return reduce_fraction((struct fraction){f1.numerator * f2.denominator +
                                               f2.numerator * f1.denominator,
                                           f1.denominator * f2.denominator});
}

// 减
struct fraction subtract_fractions(struct fraction f1, struct fraction f2) {
  return reduce_fraction((struct fraction){f1.numerator * f2.denominator -
                                               f2.numerator * f1.denominator,
                                           f1.denominator * f2.denominator});
}

// 乘
struct fraction multiply_fractions(struct fraction f1, struct fraction f2) {
  return reduce_fraction((struct fraction){f1.numerator * f2.numerator,
                                           f1.denominator * f2.denominator});
}

// 除
struct fraction divide_fractions(struct fraction f1, struct fraction f2) {
  return reduce_fraction((struct fraction){f1.numerator * f2.denominator,
                                           f1.denominator * f2.numerator});
}
