#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;

typedef struct part *p_part;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);
void clear(void);

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
    case 'd':
      dump();
      break;
    case 'r':
      restore();
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

  p_part *pnode = &inventory;
  while (NULL != *pnode) {
    // next 指针不存储
    fwrite(*pnode, sizeof(struct part) - sizeof(p_part), 1, fp);
    pnode = &(*pnode)->next;
  }

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

  clear();

  p_part *tail_null = &inventory; // 链表后端的空节点指针
  struct part buffer;             // 临时结构, 每次读取一个元素
  while (1 == fread(&buffer, sizeof(struct part) - sizeof(p_part), 1, fp)) {
    // 分配结构体空间成功后,空节点就变成了实际节点了(非NULL)
    if (NULL == (*tail_null = malloc(sizeof(struct part)))) {
      fprintf(stderr, "Error: malloc failed in restore.\n");
      exit(EXIT_FAILURE);
    }

    // 对结构体进行数据填充
    (*tail_null)->number = buffer.number;
    strcpy((*tail_null)->name, buffer.name);
    (*tail_null)->on_hand = buffer.on_hand;
    (*tail_null)->next = NULL;

    // 继续让节点指针指向尾部的空节点
    tail_null = &(*tail_null)->next;
  }

  fclose(fp);
  return;
}

void clear(void) {
  while (inventory) {
    struct part *node = inventory;
    inventory = inventory->next;
    free(node);
  }
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