#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 牌面
const char ranks[] = {'2', '3', '4', '5', '6', '7', '8',
                      '9', 't', 'j', 'q', 'k', 'a'};
// 花色
const char suits[] = {'c', 'd', 'h', 's'};

#define NUM_CARDS 5
#define NUM_RANKS ((int)(sizeof(ranks) / sizeof(ranks[0])))
#define NUM_SUITS ((int)(sizeof(suits) / sizeof(suits[0])))
#define GENERAL_SWAP(a, b)                                                     \
  {                                                                            \
    __auto_type tmp = (a);                                                     \
    (a) = (b);                                                                 \
    (b) = tmp;                                                                 \
  }

void read_cards(int cards[][2]);
void analyze_hand(int cards[][2]);
void print_result(void);
int check_ranks(char ch);
int check_suits(char ch);
void sort_card(int straight_array[]);

// 外部变量
bool straight, flush, four, three;
int pairs; // can be 0,1 or 2
// 记录每张牌出现的次数
int num_in_rank[NUM_RANKS] = {0};

int main() {

  int cards[5][2] = {0};

  while (true) {
    read_cards(cards);
    analyze_hand(cards);
    print_result();
  }

  return 0;
}

// 读取
void read_cards(int cards[][2]) {
  int cards_read = 0, rank_index, suit_index, index;
  bool bad_card, repeat;
  char ch;

  while (cards_read < NUM_CARDS) {
    bad_card = false, repeat = false;

    printf("Enter a card: ");

    // 忽略开头的空字符并读取牌面
    while ((ch = getchar()) == ' ')
      ;

    if (ch == '0')
      exit(EXIT_SUCCESS);
    else if ((index = check_ranks(ch)) == -1) {
      bad_card = true;
      printf("Bad card, ignored.\n");
      continue;
    } else {
      rank_index = index;
    }

    // 读取花色
    ch = getchar();
    if ((index = check_suits(ch)) == -1) {
      bad_card = true;
      printf("Bad card, ignored.\n");
      continue;
    } else {
      suit_index = index;
    }

    // 查重
    // cards[i][0] 记录牌面
    // cards[i][1] 记录花色
    for (int i = 0; i < cards_read; i++) {
      if (cards[i][0] == rank_index && cards[i][1] == suit_index) {
        repeat = true;
        printf("Duplicate card, ignored.\n");
        break;
      }
    }

    if (!bad_card && !repeat) {
      cards[cards_read][0] = rank_index; // 记录常量数组的对应下标值
      cards[cards_read][1] = suit_index; // 记录常量数组的对应下标值
      num_in_rank[rank_index]++;         // 同时记录牌面出现的次数

      printf("%d%d\n", rank_index, suit_index);
      cards_read++;
    }

    // 忽略后面的所有字符并开始下一次录入
    while ((ch = getchar()) != '\n')
      ;
  }
}

void analyze_hand(int cards[][2]) {
  // 检查顺子
  straight = true;
  int straight_array[NUM_CARDS] = {0};

  for (int i = 0; i < NUM_CARDS; i++) { // 将牌面信息提到数组
    straight_array[i] = cards[i][0];
  }
  sort_card(straight_array); //对牌面数组进行排序

  for (int i = 1; i < NUM_CARDS; i++) {
    if (straight_array[i] != straight_array[i - 1] + 1) {
      straight = false;
      break;
    }
  }

  // 检查4个、3个、2个
  four = false;
  three = false;
  pairs = 0;
  for (int i = 0; i < NUM_CARDS; i++) {
    if (num_in_rank[i] == 4)
      four = true;
    else if (num_in_rank[i] == 3)
      three = true;
    else if (num_in_rank[i] == 2)
      pairs++;
  }

  // 所有牌同花色
  flush = true;
  int suit = cards[0][1];
  for (int i = 1; i < NUM_CARDS; i++) {
    if (suit != cards[i][1]) {
      flush = false;
      break;
    }
  }
}

// 检查输入的牌面是否正确
int check_ranks(char ch) {
  int pos = -1;
  for (int i = 0; i < NUM_RANKS; i++) {
    if (ch == ranks[i]) {
      pos = i;
      break;
    }
  }
  return pos;
}

// 检查输入的花色是否正确
int check_suits(char ch) {
  int pos = -1;
  for (int i = 0; i < NUM_SUITS; i++) {
    if (ch == suits[i]) {
      pos = i;
      break;
    }
  }
  return pos;
}

// 牌面数组进行排序
void sort_card(int straight_array[]) {
  int n = NUM_CARDS;
  while (n > 0) {
    for (int i = 0; i < n - 1; i++) {
      if (straight_array[i] > straight_array[i + 1]) {
        GENERAL_SWAP(straight_array[i], straight_array[i + 1]);
      }
    }
    n--;
  }
}

void print_result(void) {
  if (straight && flush)
    printf("straight flush.");
  else if (four)
    printf("Four of a kind.");
  else if (three && pairs == 1)
    printf("Full house.");
  else if (flush)
    printf("Flush.");
  else if (straight)
    printf("Straight.");
  else if (three)
    printf("Three.");
  else if (pairs == 2)
    printf("Two Pair.");
  else if (pairs == 1)
    printf("Pair.");
  else
    printf("High card.");
    

  printf("\n\n");
}