#include <ctype.h>
#include <stdio.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

int read_line(char str[], int n);

int find_part(const struct part inventory[], int num_parts, int number);
void insert(struct part inventory[], int *num_parts);
void search(const struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);

int main(void) {
  struct part inventory[MAX_PARTS];
  int num_parts = 0; // 仓库的存量

  char code;
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')
      ;

    switch (code) {
    case 'i':
      insert(inventory, &num_parts);
      break;
    case 's':
      search(inventory, num_parts);
      break;
    case 'u':
      update(inventory, num_parts);
      break;
    case 'p':
      print(inventory, num_parts);
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

int find_part(const struct part inventory[], int num_parts, int number) {
  for (int i = 0; i < num_parts; i++) {
    if (inventory[i].number == number)
      return i;
  }

  return -1;
}

// 在插入的时候加入排序代码
void insert(struct part inventory[], int *num_parts) {
  int part_number;

  if (*num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  int index_insert;

  // 找到插入位置
  for (index_insert = 0; index_insert < *num_parts; index_insert++) {
    if (inventory[index_insert].number == part_number) {
      printf("Part already exists.\n");
      return;
    } else if (inventory[index_insert].number > part_number)
      break;
  }

  // 依次后移,inventy[pos]是结构类型,支持直接赋值操作
  for (int pos = *num_parts; pos >= index_insert; pos--)
    inventory[pos] = inventory[pos - 1];

  // inventory[i]在上一步已经移到数组的后一位了,这里插入新值
  inventory[index_insert].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[index_insert].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[index_insert].on_hand);

  (*num_parts)++; // 注意这个地方需要修改的是指针指向的数据
}

void search(const struct part inventory[], int num_parts) {
  int number;
  printf("Enter part number: ");
  scanf("%d", &number);

  int i = find_part(inventory, num_parts, number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else
    printf("Part not found.\n");
}

void update(struct part inventory[], int num_parts) {
  int number, change;
  printf("Enter part number: ");
  scanf("%d", &number);

  int i = find_part(inventory, num_parts, number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

void print(struct part inventory[], int num_parts) {
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