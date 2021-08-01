#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

// 灵活数组
struct vstring {
  int len;
  char chars[]; // c99+ only
};

int read_line(char str[], int n);

int main() {
  // char *reminds[MAX_REMIND];
  struct vstring *reminds[MAX_REMIND];

  char day_str[3], msg_str[MSG_LEN + 1];
  int day, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("--No space left--\n");
      break;
    }

    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;

    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);

    int i;
    for (i = 0; i < num_remind; i++) {
      // if (strcmp(day_str, reminds[i]) < 0)
      if (strcmp(day_str, reminds[i]->chars) < 0)
        break;
    }

    for (int j = num_remind; j > i; j--)
      reminds[j] = reminds[j - 1];

    // reminds[i] = malloc(2 + strlen(msg_str) + 1);
    reminds[i] = malloc(sizeof(struct vstring) + 2 + strlen(msg_str));
    if (NULL == reminds[i]) {
      printf("--No space left--\n");
      break;
    }

    // strcpy(reminds[i], day_str);
    // strcat(reminds[i], msg_str);
    strcpy(reminds[i]->chars, day_str);
    strcat(reminds[i]->chars, msg_str);
    reminds[i]->len = strlen(reminds[i]->chars);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  // for (int i = 0; i < num_remind; i++)
  //   printf("%s\n", reminds[i]);
  for (int i = 0; i < num_remind; i++) {
    for (int j = 0; j < reminds[i]->len; j++)
      printf("%c", reminds[i]->chars[j]);

    printf("\n");
  }
  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
  }

  str[i] = '\0';
  return i;
}

// Enter day and reminder: 24 Susan's birthday
// Enter day and reminder: 5 6:00 -Dinner with Marge and Russ
// Enter day and reminder: 26 Movie - "Chinatown"
// Enter day and reminder: 7 10:30 - Dental appointment
// Enter day and reminder: 12 movie - "Dazed and Confused"
// Enter day and reminder: 5 Saturday class
// Enter day and reminder: 12 Saturday class
// Enter day and reminder: 0