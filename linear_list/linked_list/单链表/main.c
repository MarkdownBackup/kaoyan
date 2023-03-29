#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 单链表
typedef struct Node {
  int data;          // 数据
  struct Node *next; // 指向下一个节点的指针
} Node, *LinkedList;

// 创建一个新链表
LinkedList InitList();

// 创建新节点
Node *newNode();

// 头插法
LinkedList HeadInsert(LinkedList head, int data);

// 尾插法
LinkedList TailInsert(LinkedList head, int data);

// 按序号查找节点
//
// index小于1 则返回NULL
//
// index大于链表的长度 则返回最后一个元素
Node *GetElem(LinkedList head, int index);

// 根据Value查找结点
//
// 没查到返回NULL
Node *LocateElem(LinkedList head, int data);

// 根据Value删除节点
bool DeleteNode(LinkedList head, int data);

// 打印链表
void PrintList(LinkedList head);

// 获取链表长度
int Length(LinkedList head);

int main() {
  LinkedList head = InitList();

  // 头插法
  HeadInsert(head, 1);
  HeadInsert(head, 2);
  HeadInsert(head, 3);
  HeadInsert(head, 4);
  HeadInsert(head, 5);

  // 尾插法
  TailInsert(head, 11);
  TailInsert(head, 12);
  TailInsert(head, 13);
  TailInsert(head, 14);
  TailInsert(head, 15);
  TailInsert(head, 16);

  // 打印
  PrintList(head);
  printf_s("链表的长度:%d\n", Length(head));

  /* // 根据序号获取元素
  printf_s("%d\n", GetElem(head, 1)->data);

  // 根据data查找节点
  printf_s("%d\n", LocateElem(head, 15)->data); */

  // 删除节点
  DeleteNode(head, 5);
  PrintList(head);
  printf_s("链表的长度:%d\n", Length(head));

  return 0;
}

LinkedList InitList() {
  // 创建头节点
  LinkedList head = newNode();

  return head;
}

Node *newNode() {
  Node *node = (Node *)malloc(sizeof(Node));
  node->next = NULL;

  return node;
}

LinkedList HeadInsert(LinkedList head, int data) {
  Node *node = newNode();
  node->data = data;

  // 头插
  node->next = head->next;
  head->next = node;

  return head;
}

LinkedList TailInsert(LinkedList head, int data) {
  Node *node = newNode();
  node->data = data;

  // 找到尾节点
  Node *cur = head->next;
  while (cur->next) {
    cur = cur->next;
  }

  // 尾插法
  node->next = cur->next;
  cur->next = node;

  return head;
}

Node *GetElem(LinkedList head, int index) {
  // 参数校验
  if (index < 1) {
    return NULL;
  }

  Node *cur = head->next;
  for (int i = 1; i < index; i++) {
    cur = cur->next;
  }

  return cur;
}

Node *LocateElem(LinkedList head, int data) {
  for (Node *cur = head->next; cur; cur = cur->next) {
    if (cur->data == data) {
      // 找到了
      return cur;
    }
  }

  return NULL;
}

bool DeleteNode(LinkedList head, int data) {
  Node *cur = head->next;
  Node *pre = head;

  // 找到要删除的节点
  while (cur && cur->data != data) {
    pre = cur;
    cur = cur->next;
  }

  // 找到了
  if (cur) {
    pre->next = cur->next;
    return true;
  }

  return false;
}

void PrintList(LinkedList head) {
  // 当前节点不为空的时候循环打印
  for (Node *cur = head->next; cur; cur = cur->next) {
    printf_s("%d ", cur->data);
  }

  printf_s("\n");
}

int Length(LinkedList head) {
  int len = 0;
  // 当前节点不为空的时候循环打印
  for (Node *cur = head->next; cur; cur = cur->next) {
    len++;
  }

  return len;
}
