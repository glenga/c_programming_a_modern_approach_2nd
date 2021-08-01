#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 1000 // 仅增大容量就可以满足要求
#define MSG_LEN 60

int read_line(char str[], int n);

int main() {
  char reminders[MAX_REMIND][MSG_LEN + 3];
  char date_str[12], msg_str[MSG_LEN + 1];
  int month, day, hour, minute, i, j, num_remind = 0;

  while (true) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter date with time and reminder: ");
    scanf("%d /%d", &month, &day);

    if (month == 0 && day == 0)
      break;

    scanf("%d :%d", &hour, &minute);
    // 格式化到变量中存放
    sprintf(date_str, "%2d/%.2d %2d:%.2d", month, day, hour, minute);
    read_line(msg_str, MSG_LEN);

    // 找到日期比当前大的行
    int input_date = month * 30 + day;
    int input_time = hour * 60 + minute;

    for (i = 0; i < num_remind; i++) {
      month = atoi(reminders[i] + 0);
      day = atoi(reminders[i] + 3);
      hour = atoi(reminders[i] + 6);
      minute = atoi(reminders[i] + 9);

      if (input_date < (month * 30 + day))
        break;
      else if (input_date == (month * 30 + day)) {
        if (input_time < (hour * 60 + minute))
          break;
      }
    }

    // 将后面所有行一次后移一行
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j - 1]);

    // 插入
    strcpy(reminders[i], date_str); // 存储days_str
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

// Enter day and reminder: 10/15 7:00 Susan's birthday
// Enter day and reminder: 10/15 6:00 Dinner with Marge and Russ
// Enter day and reminder: 2/26 20:45 Movie - "Chinatown"
// Enter day and reminder: 4/7 10:30  Dental appointment
// Enter day and reminder: 6/12  13:00 movie - "Dazed and Confused"
// Enter day and reminder: 5/5 9:00 Saturday class
// Enter day and reminder: 2/12 21:14 Saturday class
// Enter day and reminder: 0/0