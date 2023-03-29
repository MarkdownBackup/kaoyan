#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 顺序表
typedef struct SeqList {
  int *data;   // 数据
  int length;  // 数组的长度
  int maxSize; // 数组的最大容量
} SeqList;

// 初始化一个新的顺序表
//
// maxSize 顺序表的最大容量
void InitList(SeqList *head, int maxSize);

// 获取当前顺序表的长度
int Length(SeqList head);

// 根据e来查找下标
//
// 返回-1 表示不存在
int LocateElem(SeqList head, int e);

// 根据下标获取数据
//
// 返回-1 表示不存在
int GetElem(SeqList head, int index);

// 插入数据
bool ListInsert(SeqList *head, int index, int data);

// 根据下标删除数据并返回删除的数据
bool ListDelete(SeqList *head, int index, int *data);

// 打印链表
void PrintList(SeqList head);

// 判断是否为空
bool Empty(SeqList head);

// 释放一个链表
bool FreeList(SeqList *head);

// 反转顺序表
void Reverse(SeqList *head);

int main() {
  SeqList head;
  InitList(&head, 50);

  ListInsert(&head, 0, 1);
  ListInsert(&head, 0, 2);
  ListInsert(&head, 0, 3);
  ListInsert(&head, 0, 4);
  ListInsert(&head, 0, 5);
  ListInsert(&head, 3, 10);

  PrintList(head);
  printf_s("当前数组长度:%d\n", head.length);

  Reverse(&head);

  PrintList(head);
  printf_s("当前数组长度:%d\n", head.length);
}

// 初始化一个新的顺序表
void InitList(SeqList *head, int maxSize) {
  head->maxSize = maxSize;
  head->length = 0;
  head->data = (int *)malloc(sizeof(SeqList) * maxSize);
}

// 获取当前顺序表的长度
int Length(SeqList head) { return head.length; }

// 根据e来查找下标
int LocateElem(SeqList head, int e) {
  for (int i = 0; i < head.length; i++) {
    if (head.data[i] == e) {
      // 找到了
      return i;
    }
  }

  return -1;
}

// 根据下标获取数据
int GetElem(SeqList head, int index) {
  // 参数校验
  if (index >= head.length || index < 0) {
    return -1;
  }

  return head.data[index];
}

// 插入数据
bool ListInsert(SeqList *head, int index, int data) {
  // 判断是否越界
  if (index > head->length + 1 || index < 0) {
    return false;
  }

  // 判断是否超过最大存储空间
  if (index > head->maxSize) {
    return false;
  }

  // 插入元素
  if (head->length == 0 && index == 0) {
    // 第一次插入
    head->data[index] = data;
  } else {
    // 不是第一次插入
    for (int i = head->length; i > index; i--) {
      // 将后置位元素改为前面的元素
      head->data[i] = head->data[i - 1];
    }

    // 插入当前元素
    head->data[index] = data;
  }

  head->length++;

  return true;
}

bool ListDelete(SeqList *head, int index, int *data) {
  // 参数校验
  if (index >= head->length || index < 0) {
    // 要删除的数据
    *data = -999;
    return false;
  }

  // 要删除的数据
  *data = head->data[index];

  for (int i = index; i < head->length - 1; i++) {
    head->data[i] = head->data[i + 1];
  }

  head->length--;

  return true;
}

// 打印链表
void PrintList(SeqList head) {
  for (int i = 0; i < head.length; i++) {
    printf_s("%d ", head.data[i]);
  }

  printf_s("\n");
}

bool Empty(SeqList head) { return head.length == 0; }

bool FreeList(SeqList *head) {
  free(head);

  return true;
}

void Reverse(SeqList *head) {
  for (int i = 0, j = head->length-1; i < j; i++, j--) {
    int temp = head->data[i];
    head->data[i] = head->data[j];
    head->data[j] = temp;
  }
}
