#include <stdbool.h>
#include <stdio.h>

#define MaxSize 5

// 循环队列
typedef struct SeqQueue {
  int data[MaxSize]; // 数据
  int front, rear;   // 队头指针和队尾指针
  int size;          // 用来判断队列是否满了
} SeqQueue;

// 初始化队列
SeqQueue InitQueue();

// 队列是否为空
bool QueueEmpty(SeqQueue queue);

// 入队
bool Push(SeqQueue *queue, int data);

// 出队
int Pop(SeqQueue *queue);

// 获取队头元素
int GetHead(SeqQueue queue);

int main() {
  SeqQueue queue = InitQueue();

  Push(&queue, 1);
  Push(&queue, 2);
  Push(&queue, 3);
  Push(&queue, 4);
  Push(&queue, 5);
  Push(&queue, 6);
  Push(&queue, 7);

  printf_s("%d\n", Pop(&queue));
  printf_s("%d\n", Pop(&queue));
  printf_s("%d\n", Pop(&queue));
  printf_s("%d\n", Pop(&queue));
  printf_s("%d\n", Pop(&queue));
  printf_s("%d\n", Pop(&queue));

  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));
  // printf_s("%d\n", GetHead(queue));

  if (QueueEmpty(queue)) {
    printf_s("数列为空\n");
  } else {
    printf_s("不为空\n");
  }

  printf_s("队列大小:%d\n", queue.size);
  // printf_s("队头指针:%d\n", queue.front);
  // printf_s("队尾指针:%d\n", queue.rear);

  return 0;
}

SeqQueue InitQueue() {
  SeqQueue queue;

  queue.front = queue.rear = 0;
  queue.size = 0;

  return queue;
}

bool QueueEmpty(SeqQueue queue) {
  // 两个相等就认为为空
  return queue.rear == queue.front;
}

bool Push(SeqQueue *queue, int data) {
  // 判断队列是否满了
  if (queue->size == MaxSize) {
    return false;
  }

  queue->data[queue->rear] = data;
  queue->rear = queue->rear % MaxSize + 1;

  queue->size++;

  return true;
}

int Pop(SeqQueue *queue) {
  // 判断是否为空
  if (queue->rear == queue->front) {
    return -1;
  }

  int res = queue->data[queue->front];
  queue->front = queue->front % MaxSize + 1;

  queue->size--;

  return res;
}

int GetHead(SeqQueue queue) {
  // 判断是否为空
  if (QueueEmpty(queue)) {
    return -1;
  }

  return queue.data[queue.front];
}
