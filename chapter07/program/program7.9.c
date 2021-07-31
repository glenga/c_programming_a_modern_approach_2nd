#include <ctype.h>
#include <stdio.h>

int main() {
  int time, minute;
  char ch1, ch2;
  printf("Enter a 12-hour time(后缀A P AM PM): ");
  scanf("%d :%d %c%c", &time, &minute, &ch1, &ch2);
  ch1 = toupper(ch1);
  ch2 = toupper(ch2);
  if (ch2 == 'M' || iswblank(ch2) || ch2 == '\n') {
    if (ch1 == 'A')
      ;
    else if (ch1 == 'P')
      time += 12;
    else {
      printf("格式错误!!!\n");
      return 0;
    }
  } else {
    printf("格式错误!!!\n");
    return 0;
  }

  printf("Equivalent 24-hour time: %d:%d\n", time, minute);

  return 0;
}

// Enter a 12-hour time(后缀A P AM PM): 13:15 am 