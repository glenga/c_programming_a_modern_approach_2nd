#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} * inventory;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int read_line(char str[], int n);

int num_parts = 0;  // 库存条目
int max_parts = 10; // 初始化10个,不够动态翻倍

int main(void) {
  char code;

  // 主程序开始时分配内存
  if ((inventory = malloc(max_parts * sizeof(struct part))) == NULL) {
    printf("Error: malloc failed.\n");
    exit(EXIT_FAILURE);
  }

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')
      ;

    switch (code) {
    case 'i':
      insert();
      break;
    case 's':
      search();
      break;
    case 'u':
      update();
      break;
    case 'p':
      print();
      break;
    case 'q':
      return 0;
      break;
    default:
      printf("Illegal code.");
      break;
    }

    printf("\n");
  }
}

int find_part(int number) {
  for (int i = 0; i < num_parts; i++) {
    if (inventory[i].number == number)
      return i;
  }

  return -1;
}

void insert(void) {
  int part_number;

  // 插入时检查内存空间
  if (num_parts == max_parts) {
    inventory = realloc(inventory, sizeof(struct part) * max_parts * 2);
    if (NULL == inventory) {
      printf("Error: realloc failed!\n");
      exit(EXIT_FAILURE);
    }
  }

  // if (num_parts == MAX_PARTS) {
  //   printf("Database is full; can't add more parts.\n");
  //   return;
  // }

  printf("Enter part number: ");
  scanf("%d", &part_number);
  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);

  num_parts++;
}

void search(void) {
  int number;
  printf("Enter part number: ");
  scanf("%d", &number);

  int i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else
    printf("Part not found.\n");
}

void update(void) {
  int number, change;
  printf("Enter part number: ");
  scanf("%d", &number);

  int i = find_part(number);
  if (i >= 0) {
    printf("Enter quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

void print(void) {
  printf("Part Number        Part Name          Quantity on hand\n");
  for (int i = 0; i < num_parts; i++)
    printf("%7d            %-19s%10d\n", inventory[i].number, inventory[i].name,
           inventory[i].on_hand);
}

int read_line(char str[], int n) {
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;

  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;

    ch = getchar();
  }

  str[i] = '\0';
  return i;
}

// Enter operation code: i
// Enter part number: 528
// Enter part name: Disk drive
// Enter quantity on hand: 10

// Enter operation code: s
// Enter part number: 528
// Part name: Disk drive
// Quantity on hand: 10

// Enter operation code: s
// Enter part number: 914
// Part not found.

// Enter operation code: i
// Enter part number: 914
// Enter part name: Printer cable
// Enter quantity on hand: 5

// Enter operation code: u
// Enter part number: 528
// Enter change in quantity on hand: -2

// Enter operation code: s
// Enter part number: 528
// Part name: Disk drive
// Quantity on hand: 8
