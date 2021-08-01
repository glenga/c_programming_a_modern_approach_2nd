#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0; // 库存条目

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);
int read_line(char str[], int n);

int main(void) {
  char code;
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
    case 'd':
      dump();
      break;
    case 'r':
      restore();
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

// 转储
void dump(void) {
  char filename[255];
  printf("Enter name of output file: ");
  read_line(filename, 255);

  FILE *fp = fopen(filename, "wb");
  if (NULL == fp) {
    fprintf(stderr, "error open file %s\n", filename);
    return;
  }

  fwrite(inventory, sizeof(struct part), num_parts, fp);
  fclose(fp);
  return;
}

// 恢复
void restore(void) {
  char filename[255];
  printf("Enter name of input file: ");
  read_line(filename, 255);

  FILE *fp = fopen(filename, "rb");
  if (NULL == fp) {
    fprintf(stderr, "error open file %s\n", filename);
    return;
  }

  num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);
  fclose(fp);

  return;
}

void insert(void) {
  int part_number;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

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
    printf("Enter change in quantity on hand: ");
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

// Enter operation code: r
// Enter name of input file: inventory.dat

// Enter operation code: p
// Part Number        Part Name          Quantity on hand
//     528            Disk drive                 10
//     914            Printer cable               5
//     456            Memory                     20

// Enter operation code:
