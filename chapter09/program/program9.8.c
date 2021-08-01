#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_INT(a, b) (rand() % (b - a) + a)

int roll_dice(void);
bool play_game(void);

int main() {
  int wins = 0, losses = 0;

  srand((unsigned)time(NULL));

  while (true) {
    if (play_game())
      wins++;
    else
      losses++;

  lab:
    printf("\nplay again(Y/N)?");

    if (getch() == 'y' || getch() == 'Y') {
      continue;
    } else if (getch() == 'n' || getch() == 'N')
      break;
    else
      goto lab;
  }

  printf("Wins: %d  Losses: %d\n", wins, losses);

  return 0;
}

// 1-6之间两个随机数和
int roll_dice(void) { return RANGE_INT(1, 7) + RANGE_INT(1, 7); }

// 游戏逻辑
bool play_game(void) {
  int rolled, target = 0;

  while (true) {
    rolled = roll_dice();
    printf("You rolled: %d\n", rolled);

    if (rolled == 7 || rolled == 11) {
      printf("YOU WIN!!!\n");
      return true;
    } else if (rolled == 2 || rolled == 3 || rolled == 12) {
      printf("YOU LOSS!\n");
      return false;
    } else if (rolled == target) {
      printf("YOU WIN!!!\n");
      return true;
    }

    if (target == 0) {
      target = rolled;
      printf("You point is: %d\n", target);
    }
  }
}