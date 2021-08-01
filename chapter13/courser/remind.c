#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main() {
  char reminders[MAX_REMIND][MSG_LEN + 3];
  char days_str[3], msg_str[MSG_LEN + 1];
  int day, i, j, num_remind = 0;

  while (true) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;

    sprintf(days_str, "%2d", day); // 格式化到变量中存放
    read_line(msg_str, MSG_LEN);

    // 找到日期比当前大的行
    for (i = 0; i < num_remind; i++) {
      if (strcmp(days_str, reminders[i]) < 0)
        break;
    }

    // 将后面所有行一次后移一行
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j - 1]);

    // 插入
    strcpy(reminders[i], days_str); // 存储days_str
    strcat(reminders[i], msg_str);  // 拼接提醒信息

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

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