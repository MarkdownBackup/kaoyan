#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 循环双链表
typedef struct DNode {
  int data;
  struct DNode *next;
  struct DNode *prior;

} DNode, *DLinkedList;

// 初始化循环双链表
DLinkedList InitList();

DNode *newNode();

// 头插
DLinkedList HeadInsert(DLinkedList head, int data);

// 删除
bool DeleteNode(DLinkedList head, int data);

// 打印链表
void PrintList(DLinkedList head);

int main() {
  DLinkedList head = InitList();

  // 头插
  HeadInsert(head, 1);
  HeadInsert(head, 2);
  HeadInsert(head, 3);
  HeadInsert(head, 4);
  HeadInsert(head, 5);

  // 打印
  PrintList(head);

  // 删除节点
  DeleteNode(head, 5);

  PrintList(head);

  return 0;
}

DLinkedList InitList() {
  DLinkedList head = newNode();

  // 循环
  head->next = head;
  head->prior = head;

  return head;
}

DNode *newNode() {
  DNode *node = (DNode *)malloc(sizeof(DNode));
  node->next = node->prior = NULL;

  return node;
}

DLinkedList HeadInsert(DLinkedList head, int data) {
  DNode *node = newNode();
  node->data = data;

  // 与双链表不同 循环双链表没有第一次和第二次及以后有区别
  node->next = head->next;
  head->next->prior = node;

  head->next = node;
  node->prior = head;

  return head;
}

bool DeleteNode(DLinkedList head, int data) {
  DNode *cur = head->next;

  // 找到要删除的节点
  while (cur != head && cur->data != data) {
    cur = cur->next;
  }

  // 找到了
  if (cur != head) {

    // 与双链表不同 循环双链表没有最后一个节点之分
    cur->prior->next = cur->next;
    cur->next->prior = cur->prior;
    free(cur);
    return true;
  }

  return false;
}

void PrintList(DLinkedList head) {
  for (DNode *cur = head->next; cur != head; cur = cur->next) {
    printf_s("%d ", cur->data);
  }

  printf_s("\n");
}
