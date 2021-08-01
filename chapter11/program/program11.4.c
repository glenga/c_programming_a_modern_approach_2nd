#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

void read_cards(int num_in_rank[], int num_in_suit[]);
void analyze_hand(int num_in_rank[], int num_in_suit[], bool *straight,
                  bool *flush, bool *four, bool *three, int *pairs);
void print_result(bool *straight, bool *flush, bool *four, bool *three,
                  int *pairs);

int main() {
  int num_in_rank[NUM_RANKS];
  int num_in_suit[NUM_SUITS];

  // 移到内部, 使用指针访问
  bool straight, flush, four, three;
  int pairs; // can be 0,1 or 2

  while (true) {
    read_cards(num_in_rank, num_in_suit);
    analyze_hand(num_in_rank, num_in_suit, &straight, &flush, &four, &three,
                 &pairs);
    print_result(&straight, &flush, &four, &three, &pairs);
  }

  return 0;
}

// 读取
void read_cards(int num_in_rank[], int num_in_suit[]) {
  // 一整副牌 13*4 bool数组,选定的牌为true
  bool card_exists[NUM_RANKS][NUM_SUITS] = {0};
  //  记录同一牌面的数量; 初始化
  for (int i = 0; i < NUM_RANKS; i++)
    num_in_rank[i] = 0;

  // 记录同一花色的数量; 初始化
  for (int i = 0; i < NUM_SUITS; i++)
    num_in_suit[i] = 0;

  bool bad_card; // 错误输入开关
  int cards_read = 0;
  char ch;
  int rank = 0, suit = 0;

  while (cards_read < NUM_CARDS) {
    printf("Enter a card: ");
    bad_card = false;

    ch = getchar();
    switch (ch) {
    case '0':
      exit(EXIT_SUCCESS);
    case '2':
      rank = 0;
      break;
    case '3':
      rank = 1;
      break;
    case '4':
      rank = 2;
      break;
    case '5':
      rank = 3;
      break;
    case '6':
      rank = 4;
      break;
    case '7':
      rank = 5;
      break;
    case '8':
      rank = 6;
      break;
    case '9':
      rank = 7;
      break;
    case 't':
    case 'T':
      rank = 8;
      break;
    case 'j':
    case 'J':
      rank = 9;
      break;
    case 'q':
    case 'Q':
      rank = 10;
      break;
    case 'k':
    case 'K':
      rank = 11;
      break;
    case 'a':
    case 'A':
      rank = 12;
      break;
    default:
      bad_card = true;
    }

    ch = getchar();
    switch (ch) {
    case 'c':
    case 'C':
      suit = 0;
      break;
    case 'd':
    case 'D':
      suit = 1;
      break;
    case 'h':
    case 'H':
      suit = 2;
      break;
    case 's':
    case 'S':
      suit = 3;
      break;
    default:
      bad_card = true;
    }

    while ((ch = getchar()) != '\n') {
      if (ch != ' ')
        bad_card = true;
    }

    if (bad_card) {
      printf("Bad card, ignored.\n");
    } else if (card_exists[rank][suit]) {
      printf("Duplicate card, ignored.\n");
    } else {
      num_in_rank[rank]++;
      num_in_suit[suit]++;
      card_exists[rank][suit] = true;
      cards_read++;
    }
  }
}

// 牌面分析
void analyze_hand(int num_in_rank[], int num_in_suit[], bool *straight,
                  bool *flush, bool *four, bool *three, int *pairs) {
  int num_consec = 0;
  *straight = false;
  *flush = false;
  *four = false;
  *three = false;
  *pairs = 0;

  // 所有牌同花色
  for (int i = 0; i < NUM_SUITS; i++) {
    if (num_in_suit[i] == NUM_CARDS)
      *flush = true;
  }

  // 顺子
  int i = 0;
  while (num_in_rank[i] == 0) // 忽略没有的牌面
    i++;
  for (; i < NUM_RANKS && num_in_rank[i] > 0; i++) // 一旦不连续 循环结束
    num_consec++;

  if (num_consec == NUM_CARDS) {
    *straight = true;
  }

  // 检查4个、3个、2个
  for (int i = 0; i < NUM_RANKS; i++) {
    if (num_in_rank[i] == 4)
      *four = true;
    else if (num_in_rank[i] == 3)
      *three = true;
    else if (num_in_rank[i] == 2)
      ++*pairs;
  }
}

void print_result(bool *straight, bool *flush, bool *four, bool *three,
                  int *pairs) {
  if (*straight && *flush)
    printf("straight flush.");
  else if (*four)
    printf("Four of a kind.");
  else if (*three && *pairs == 1)
    printf("Full house.");
  else if (*flush)
    printf("Flush.");
  else if (*straight)
    printf("Straight.");
  else if (*three)
    printf("Three.");
  else if (*pairs == 2)
    printf("Two Pair.");
  else if (*pairs == 1)
    printf("Pair.");
  else
    printf("High card.");

  printf("\n\n");
}