#include <stdio.h>

int main(void) {
  char *tens[] = {"twenty", "thirty",  "forty",  "fifty",
                  "sixty",  "seventy", "eighty", "ninety"},
       *teens[] = {"ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                   "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
       *ones[] = {"",      "-one", "-two",   "-three", "-four",
                  "-five", "-six", "-seven", "-eight", "-nine"};

  int num;
  printf("Enter a two-digit number: ");
  scanf("%d", &num);
  printf("You Entered the number ");
  if (num / 10 == 1)
    printf("%s\n", teens[num % 10]);
  else
    printf("%s%s\n", tens[num / 10 - 2], ones[num % 10]);

  return 0;
}

// Enter a two-digit number: 67