#include <ctype.h>
#include <stdio.h>

int main() {
    
  int n = 0;
  char ch[100] = {0};

  printf("Enter message: ");

  while ((ch[n] = getchar()) != '\n') {
    switch (ch[n]) {
      case 'a':
      ch[n] = '4';
      break;
      case 'b':
      ch[n] = '8';
      break; 
    case 'o':
      ch[n] = '0';
      break;
    case 'e':
      ch[n] = '3';
      break;
    case 'i':
      ch[n] = '1';
      break;
    case 's':
      ch[n] = '5';
      break;
    default:
      ch[n] = toupper(ch[n]);
      break;
    }
    n++;
  }
  printf("In B1FF-speak: ");
  for (int i = 0; i < n; i++)
    printf("%c", ch[i]);

  printf("!!!!!!!!!!\n");
  return 0;
}

// Enter message: Hey dude, C is rilly cool