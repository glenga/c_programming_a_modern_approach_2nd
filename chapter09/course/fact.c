// 阶乘
int fact(int n) {
  //   if (n <= 1)
  //     return 1;
  //   else
  //     return n * fact(n - 1);

  return n <= 1 ? 1 : n * fact(n - 1);
}

int fact1(int n) { return n <= 1 ? 1 : n * fact(n - 1); }

