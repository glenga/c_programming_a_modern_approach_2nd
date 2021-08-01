#include <stdio.h>

int main() {
  double a = 83.7361;
  double b = 29748.6607;
  double c = 1054932234.0;
  double d = 0.0000235218;

  // #不能删除g占位符输出的尾部0
  printf("%#012.5g\n", a);
  printf("%#012.5g\n", b);
  printf("%#012.5g\n", c);
  printf("%#012.5g\n", d);
}