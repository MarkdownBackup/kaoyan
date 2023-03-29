#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 双链表
typedef struct DNode {
  int data;
  struct DNode *next;
  struct DNode *prior;

} DNode, *DLinkedList;

// 初始化双链表
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
  DeleteNode(head, 1);

  PrintList(head);

  return 0;
}

DLinkedList InitList() {
  DLinkedList head = newNode();

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

  if (!head->next) {
    // 第一场插入
    node->prior = head;
    head->next = node;
  } else {
    node->next = head->next;
    head->next->prior = node;

    head->next = node;
    node->prior = head;
  }

  return head;
}

bool DeleteNode(DLinkedList head, int data) {
  DNode *cur = head->next;

  // 找到要删除的节点
  while (cur && cur->data != data) {
    cur = cur->next;
  }

  // 找到了
  if (cur) {
    if (!cur->next) {
      // 最后一个节点特殊处理
      cur->prior->next = cur->next;
      free(cur);
      return true;
    }

    cur->prior->next = cur->next;
    cur->next->prior = cur->prior;
    free(cur);
    return true;
  }

  return false;
}

void PrintList(DLinkedList head) {
  for (DNode *cur = head->next; cur; cur = cur->next) {
    printf_s("%d ", cur->data);
  }

  printf_s("\n");
}
