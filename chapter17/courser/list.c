#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

// 从链表头部插入
struct node *add_to_list(struct node *list, int n) {
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (NULL == new_node) {
    printf("Error: malloc failed in add_to_list.\n");
    exit(EXIT_FAILURE);
  }

  new_node->value = n;
  new_node->next = list;
  return new_node;
}

// 从链表头部插入(我们需要修改的是一个指针,必须以传址的方式调用才有效(&p),
// 所以形参为指向指针的指针)
void add_to_list2(struct node **list, int n) {
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (NULL == new_node) {
    printf("Error: malloc failed in add_to_list.\n");
    exit(EXIT_FAILURE);
  }

  new_node->value = n;
  new_node->next = *list;
  *list = new_node; // 链表头重新设置
}

struct node *search_list(struct node *list, int n) {
  for (; list != NULL && list->value != n; list = list->next)
    ;

  return list;
}

struct node *delete_from_list(struct node *list, int n) {
  struct node *cur, *prev;

  for (cur = list, prev = NULL; cur != NULL && cur->value != n;
       prev = cur, cur = cur->next)
    ;

  if (cur == NULL) // 没有找到
    return list;

  if (prev == NULL) // 删除表头, 修改了复制进来的指针结构, 函数返回
    list = list->next;
  else
    prev->next = cur->next;

  free(cur);
  return list;
}

// 修改一个指针结构, 需要对指针结构取址调用, 因此形参应为指针的指针形式
void delete_from_list1(struct node **list, int n) {
  struct node *prev = NULL, *cur = *list;
  for (; cur != NULL && cur->value != n; prev = cur, cur = cur->next)
    ;

  if (NULL == cur) // 没有找到
    return;

  if (NULL == prev) // 删除表头
    *list = (*list)->next;
  else // 一般情况
    prev->next = cur->next;

  free(cur);
}

// 修改一个指针结构, 需要对指针结构取址调用, 因此形参应为指针的指针形式
void delete_from_list2(struct node **list, int n) {
  struct node *pnode = *list;

  // n 在表头
  if (pnode->value == n) {
    *list = (*list)->next;
    free(pnode);
    return;
  }

  // 一般情况
  for (; pnode->next && pnode->next->value != n; pnode = pnode->next)
    ;

  if (pnode->next && n == pnode->next->value) {
    struct node *temp = pnode->next;
    pnode->next = temp->next;
    free(temp);
  }
}

void read_numbers(struct node **first) {
  int n;

  printf("Enter a series of intergers(0 to terminate): ");
  for (;;) {
    scanf("%d", &n);
    if (0 == n)
      return;

    *first = add_to_list(*first, n);
  }
}

void print(struct node *list) {
  while (list != NULL) {
    printf("%d ", list->value);
    list = list->next;
  }

  printf("\n");
}

int main() {
  struct node *list = NULL;
  char code;
  int n;
  for (;;) {
    printf("Enter code: ");
    scanf(" %c", &code);
    switch (code) {
    case 'i':
      read_numbers(&list);
      break;
    case 'd':
      printf("Enter deleted: ");
      scanf("%d", &n);
      // list = delete_from_list(list, n);
      // delete_from_list1(&list, n);
      delete_from_list2(&list, n);
      break;
    case 'p':
      print(list);
      break;
    case 'q':
      exit(EXIT_SUCCESS);
    }
  }

  return 0;
}

// Enter code: i
// Enter a series of intergers(0 to terminate): 100 200 300 400 500 600 0
// Enter code: p
// 600 500 400 300 200 100
// Enter code: d
// Enter deleted: 300
// Enter code: p
// 600 500 400 200 100
// Enter code: d
// Enter deleted: 400
// Enter code: p
// 600 500 200 100
// Enter code: i
// Enter a series of intergers(0 to terminate): 300 400 0
// Enter code: p
// 400 300 600 500 200 100
// Enter code: q