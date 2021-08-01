#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  struct lconv *locale;
  int grouping, mon_grouping;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s locale\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (setlocale(LC_ALL, argv[1]) == NULL) {
    fprintf(stderr, "No information available for %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  locale = localeconv();

  grouping = (int)locale->grouping[0];
  mon_grouping = (int)locale->mon_grouping[0];
  // 非货币数字的小数点，例如 100.25。
  printf("decimal_point = \"%s\"\n", locale->decimal_point);
  // 非货币数字的千位分隔符，例如 12,172,390,000。
  printf("thousands_sep = \"%s\"\n", locale->thousands_sep);
  // 显示数字时分隔符设置为几位
  printf("grouping = \"%d\"\n", grouping);
  // 货币量（表示货币的数字）的小数点，例如 ￥ 25.5。
  printf("mon_decimal_point = \"%s\"\n", locale->mon_decimal_point);
  // 货币量的千位分隔符，例如 ￥ 25,000。
  printf("mon_thousands_sep = \"%s\"\n", locale->mon_thousands_sep);
  // 千位分隔符 mon_decimal_point 分隔货币量时，每一个分组包含的数字个数
  printf("mon_grouping = \"%d\"\n", mon_grouping);
  // 用于表示非负（正数或者零）货币量的符号，一般为空字符串。
  printf("positive_sign = \"%s\"\n", locale->positive_sign);
  // 用于表示负的货币量的符号，一般为-，也就是负号。
  printf("negative_sign = \"%s\"\n", locale->negative_sign);
  // 本地货币符号。
  printf("currency_symbol = \"%s\"\n", locale->currency_symbol);
  // 国际货币符号（国际货币代码）。
  printf("int_curr_symbol = \"%s\"\n", locale->int_curr_symbol);
  // 货币量的小数部分保留的位数，或者说货币量的小数点右侧的数字个数。
  printf("frac_digits = \"%d\"\n", locale->frac_digits);
  // 货币符号 currency_symbol 是否位于非负（正数或者零）货币量之前。
  printf("p_cs_precedes = \"%d\"\n", locale->p_cs_precedes);
  // 货币符号 currency_symbol 是否位于负（正数或者零）的货币量之前。
  printf("n_cs_precedes = \"%d\"\n", locale->n_cs_precedes);
  // 货币符号 currency_symbol 与非负（正说或者零）货币量之间是否有空格。
  printf("p_sep_by_space = \"%d\"\n", locale->p_sep_by_space);
  // 货币符号 currency_symbol 与负的货币量之间是否有空格。
  printf("n_sep_by_space = \"%d\"\n", locale->n_sep_by_space);
  // 非负（正数或者零）货币量中 positive_sign 的位置
  printf("p_sign_posn = \"%d\"\n", locale->p_sign_posn);
  // 负的货币量中 negative_sign 的位置
  printf("n_sign_posn = \"%d\"\n", locale->n_sign_posn);
  // 	和 frac_digits 类似。不过 frac_digits
  // 针对的是当地（当前区域设置）的货币格式，而 int_frac_digits
  // 针对的是国际货币格式。
  printf("int_frac_digits = \"%d\"\n", locale->int_frac_digits);
  // 我的机器上没找到定义
  // printf("int_p_cs_precedes = \"%d\"\n", locale->int_p_cs_precedes);
  // printf("int_n_cs_precedes = \"%d\"\n", locale->int_n_cs_precedes);
  // printf("int_p_sep_by_space = \"%d\"\n", locale->int_p_sep_by_space);
  // printf("int_n_sep_by_space = \"%d\"\n", locale->int_n_sep_by_space);
  // printf("int_p_sign_posn = \"%d\"\n", locale->int_p_sign_posn);
  // printf("int_n_sign_posn = \"%d\"\n", locale->int_n_sign_posn);

  exit(EXIT_SUCCESS);
}

// test: .\program25.2.exe Chinese
