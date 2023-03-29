#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 循环队列
typedef struct SeqQueue {
  int data; // 数据
  struct SeqQueue *next;
} SeqQueue;

typedef struct LinkedQueue {
  SeqQueue *front, *rear;
} *LinkedQueue;

// 初始化队列
LinkedQueue InitQueue();

// 创建节点
SeqQueue *newNode();

// 队列是否为空
bool QueueEmpty(LinkedQueue queue);

// 入队
bool Push(LinkedQueue queue, int data);

// 出队
int Pop(LinkedQueue queue);

// 获取队头元素
int GetHead(LinkedQueue queue);

int main() {
  LinkedQueue queue = InitQueue();

  Push(queue, 1);
  Push(queue, 2);
  Push(queue, 3);
  Push(queue, 4);

  if (QueueEmpty(queue)) {
    printf_s("队列为空\n");
  } else {
    printf_s("不为空\n");
  }

  printf_s("%d\n", Pop(queue));
  printf_s("%d\n", Pop(queue));
  printf_s("%d\n", Pop(queue));
  printf_s("%d\n", Pop(queue));
  printf_s("%d\n", Pop(queue));

  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));

  return 0;
}

LinkedQueue InitQueue() {
  LinkedQueue queue;

  queue->rear = queue->front = newNode();

  return queue;
}

SeqQueue *newNode() {
  SeqQueue *node = (SeqQueue *)malloc(sizeof(SeqQueue));
  node->next = NULL;

  return node;
}

bool QueueEmpty(LinkedQueue queue) { return queue->front == queue->rear; }

bool Push(LinkedQueue queue, int data) {
  // 尾插
  SeqQueue *node = newNode();
  node->data = data;

  queue->rear->next = node;
  queue->rear = queue->rear->next;

  return true;
}

int Pop(LinkedQueue queue) {
  // 判断是否为空
  if (QueueEmpty(queue)) {
    return -1;
  }

  // 头出
  SeqQueue *node = queue->front->next;
  queue->front->next = node->next;

  // 如果只有一个元素
  if (queue->rear == node) {
    queue->rear = queue->front;
  }

  int res = node->data;

  // 释放空间
  free(node);

  return res;
}

int GetHead(LinkedQueue queue) {
  // 判断是否为空
  if (QueueEmpty(queue)) {
    return -1;
  }

  return queue->front->next->data;
}
