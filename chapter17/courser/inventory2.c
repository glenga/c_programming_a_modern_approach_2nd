#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int read_line(char str[], int n);

int main() {
  char code;
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);

    while (getchar() != '\n') // 忽略剩余的字符
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
    default:
      printf("Illegal code.");
      break;
    }
    printf("\n");
  }
  return 0;
}

void insert(void) {
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));
  if (new_node == NULL) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &new_node->number);

  for (cur = inventory, prev = NULL;
       cur != NULL && cur->number > new_node->number;
       prev = cur, cur = cur->next)
    ;

  if (cur != NULL && cur->number > new_node->number) {
    printf("part already exists.\n");
    free(new_node); // 这里注意要及时释放分配的内存
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &new_node->on_hand);

  new_node->next = cur;
  if (prev == NULL)
    inventory = new_node;
  else
    prev->next = new_node;
}

void search(void) {
  int number;

  printf("Enter part number: ");
  scanf("%d", &number);

  struct part *p = find_part(number);
  if (p != NULL) {
    printf("Part name: %s\n", p->name);
    printf("quantity on hand: %d\n", p->on_hand);
  } else
    printf("part not found.\n");
}

void update(void) {
  int number, change;

  printf("Enter part number: ");
  scanf("%d", &number);

  struct part *p = find_part(number);
  if (p != NULL) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
  } else
    printf("part not found.\n");
}
void print(void) {
  struct part *p;
  printf("Part Number        Part Name          Quantity on hand\n");
  for (p = inventory; p != NULL; p = p->next)
    printf("%7d            %-19s%10d\n", p->number, p->name, p->on_hand);
}

struct part *find_part(int number) {
  struct part *p;
  for (p = inventory; p != NULL && number == p->number; p = p->next)
    ;

  if (p != NULL && number == p->number)
    return p;

  return NULL;
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