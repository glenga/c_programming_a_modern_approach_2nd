#include <stdio.h>

#define BUFF_SIZE 100

int main() {
  char sales_rank[BUFF_SIZE];

  char *str1 = "#989";
  char *str2 = "#24,675";
  char *str3 = "#1,162,620";
  char *str4 = "1,162,620";

  // `%*`  `*`表示占用的位宽n，
  // 在后面的参数列表中必须指出占用的位数n，省略了n即不显示
  
  sscanf(str1,
         str1[0] == '#' ? "%*[#]%[0123456789,]" : "%*[^#]*[#]%[0123456789,]",
         sales_rank);
  printf("%s\n", sales_rank);

  sscanf(str2,
         str2[0] == '#' ? "%*[#]%[0123456789,]" : "%*[^#]*[#]%[0123456789,]",
         sales_rank);
  printf("%s\n", sales_rank);

  sscanf(str3,
         str3[0] == '#' ? "%*[#]%[0123456789,]" : "%*[^#]*[#]%[0123456789,]",
         sales_rank);
  printf("%s\n", sales_rank);

  sscanf(str4,
         str4[0] == '#' ? "%*[#]%[0123456789,]" : "%*[^#]*[#]%[0123456789,]",
         sales_rank);
  printf("%s\n", sales_rank);

  return 0;
}