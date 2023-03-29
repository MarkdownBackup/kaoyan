#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef struct SeqStack {
  int data[MaxSize]; // 栈中的元素
  int top;           // 栈顶指针
} SeqStack;

// 初始化一个栈
SeqStack InitStack();

// 判断栈是否为空
bool StackEmpty(SeqStack stack);

// 入栈
bool Push(SeqStack *stack, int data);

// 出栈
int Pop(SeqStack *stack);

// 获取栈顶元素
int GetTop(SeqStack stack);

int main() {
  SeqStack stack = InitStack();

  Push(&stack, 1);
  Push(&stack, 2);
  Push(&stack, 3);
  Push(&stack, 4);
  Push(&stack, 5);

  if(StackEmpty(stack)){
    printf_s("栈为空\n");
  }else{
    printf_s("栈不为空\n");
  }

  printf_s("%d\n", Pop(&stack));
  

  return 0;
}

SeqStack InitStack() {
  SeqStack stack;

  // 栈顶指针初始化为-1
  stack.top = -1;

  return stack;
}

bool StackEmpty(SeqStack stack) { return stack.top == -1; }

bool Push(SeqStack *stack, int data) {
  // 判断栈是否满了
  if (stack->top == MaxSize - 1) {
    return false;
  }

  stack->top++;
  stack->data[stack->top] = data;

  return true;
}

int Pop(SeqStack *stack) {
  // 判断栈是否为空
  if (stack->top == -1) {
    return -1;
  }

  // 出栈
  int res = stack->data[stack->top];
  stack->top--;

  return res;
}

int GetTop(SeqStack stack) {
  // 判断栈是否为空
  if (StackEmpty(stack)) {
    return -1;
  }

  return stack.data[stack.top];
}
