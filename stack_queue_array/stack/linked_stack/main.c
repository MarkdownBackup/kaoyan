#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 链式栈
typedef struct StackNode {
  int data;               // 栈中的元素
  struct StackNode *next; // 指针
} StackNode, *LinkedStack;

// 初始化一个栈
LinkedStack InitStack();

// 创建一个栈节点
StackNode *newNode();

// 判断栈是否为空
bool StackEmpty(LinkedStack stack);

// 入栈
bool Push(LinkedStack stack, int data);

// 出栈
int Pop(LinkedStack stack);

// 获取栈顶元素
int GetTop(LinkedStack stack);

int main() {
  LinkedStack stack = InitStack();

  return 0;
}

LinkedStack InitStack() {
  LinkedStack stack = newNode();

  // 入栈
  Push(stack, 1);
  Push(stack, 2);
  Push(stack, 3);
  Push(stack, 4);

  if (StackEmpty(stack)) {
    printf_s("栈为空\n");
  } else {
    printf_s("栈不为空\n");
  }

  printf_s("%d\n", Pop(stack));
  printf_s("%d\n", Pop(stack));

  printf_s("%d\n", GetTop(stack));
  printf_s("%d\n", GetTop(stack));
  printf_s("%d\n", GetTop(stack));
  printf_s("%d\n", GetTop(stack));
  printf_s("%d\n", GetTop(stack));

  return stack;
}

StackNode *newNode() {
  StackNode *node = (StackNode *)malloc(sizeof(StackNode));
  node->next = NULL;

  return node;
}

bool StackEmpty(LinkedStack stack) { return stack->next == NULL; }

bool Push(LinkedStack stack, int data) {
  // 头插
  StackNode *node = newNode();
  node->data = data;

  node->next = stack->next;
  stack->next = node;

  return true;
}

int Pop(LinkedStack stack) {
  // 判断是否为空
  if (StackEmpty(stack)) {
    return -1;
  }

  // 获取要出栈的元素
  StackNode *node = stack->next;
  int res = node->data;

  stack->next = node->next;

  free(node);

  return res;
}

int GetTop(LinkedStack stack) {
  // 判断是否为空
  if (StackEmpty(stack)) {
    return -1;
  }

  return stack->next->data;
}
