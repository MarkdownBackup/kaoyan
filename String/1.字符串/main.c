#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 字符串
typedef struct {
  char *buf;  // 具体的数据
  int length; // 字符串的实际长度
  // int free;   // 字符串未使用的空间
} String;

// 初始化或清空字符串
void InitString(String *str);

// 赋值操作 将str赋值为chars
bool StrAssign(String *str, char *chars);

// 字符串复制
//
// 将src中的数据复制到des中
bool StrCopy(String *des, String src);

// 字符串比较
//
// s1 > s2 返回值>0
//
// s1 < s2 返回值<0
//
// s1 = s2 返回值=0
int StrCompare(String s1, String s2);

// 返回s的长度
int StrLength(String s);

// 获取字串
//
// 将sub置为字符串s的第pos个字符起长度为len的子串
bool SubString(String *sub, String s, int pos, int len);

// 拼接s1和s2
// BUG: 不会写 我真是废物
bool Concat(String *des, String s1, String s2);

// 定位 KMP算法
// TODO:
int Index(String haystack, String needle);

// 字符串匹配 暴力解法
//
// 匹配成功 返回第一个匹配到的下标
//
// 匹配失败 返回-1
int strStrWithSimple(String haystack, String needle);

int strStr(String haystack, String needle);

// 清空操作,将s置为空串
void ClearString(String *s);

// 销毁串,释放空间
void DestoryString(String *s);

// 打印字符串
void PrintString(String str);

int main() {
  String s;

  InitString(&s);

  StrAssign(&s, "zhang3 woaini");

  PrintString(s);
  printf_s("字符串的长度:%d\n", StrLength(s));

  printf_s("-------\n");

  String copy;
  InitString(&copy);

  // StrCopy(&copy, s);

  StrAssign(&copy, "hello");

  PrintString(copy);
  printf_s("copy 字符串的长度:%d\n", StrLength(copy));

  printf_s("s比copy长:%d\n", StrCompare(s, copy));

  printf_s("-------\n");

  // String sub;
  // InitString(&sub);
  //
  // if (SubString(&sub, s, 0, 999)) {
  //   printf_s("获取子串成功\n");
  // } else {
  //   printf_s("获取子串失败\n");
  // }
  //
  // PrintString(sub);
  // printf_s("sub 子字符串的长度:%d\n", StrLength(sub));

  // String concat;
  //
  // InitString(&concat);
  //
  // Concat(&concat, s, copy);
  //
  // PrintString(concat);
  // printf_s("concat 拼接后字符串的长度:%d\n", StrLength(concat));
  //
  // printf_s("-------\n");

  // ClearString(&copy);
  // PrintString(copy);
  // printf_s("copy 字符串的长度:%d\n", StrLength(copy));
  //
  // printf_s("-------\n");

  // DestoryString(&s);
  //
  // PrintString(s);

  printf_s("----字符串匹配----\n");

  String a;
  InitString(&a);
  StrAssign(&a, "abcabdabcabc");

  String b;
  InitString(&b);
  StrAssign(&b, "ababaa");

  printf_s("%d\n", Index(a, b));

  printf_s("-------\n");

  return 0;
}

void InitString(String *str) {
  str->buf = NULL;
  str->length = 0;
  // str->free = 0;
}

bool StrAssign(String *str, char *chars) {
  // 清空str防止内存泄漏
  InitString(str);

  // 获取chars的长度
  for (int i = 0; chars[i]; i++) {
    str->length++;
  }

  str->buf = chars;

  return true;
}

bool StrCopy(String *des, String src) {
  // 清空str防止内存泄漏
  InitString(des);

  des->length = src.length;
  des->buf = src.buf;
  return true;
}

int StrCompare(String s1, String s2) {
  // 挨个对比每个字符
  for (int i = 0; i < s1.length && i < s2.length; i++) {
    if (s1.buf[i] != s2.buf[i]) {
      return s1.buf[i] - s2.buf[i];
    }
  }

  // 此时有一个字符串更长或等长
  return s1.length - s2.length;
}

int StrLength(String s) { return s.length; }

// 获取字串
//
// 将sub置为字符串s的第pos个字符起长度为len的子串
bool SubString(String *sub, String s, int pos, int len) {
  // 判断参数是否越界
  if (pos > s.length || pos < 0 || len < 0) {
    return false;
  }

  // 防止sub没有初始化
  InitString(sub);

  // 保护 防止len越界
  if (len > s.length - pos) {
    len = s.length - pos;
  }

  sub->length = len;

  // 获取pos的起始地址
  sub->buf = &s.buf[pos];

  return true;
}

// BUG: 不会写 我真是废物
bool Concat(String *des, String s1, String s2) {
  // 防止没有初始化
  InitString(des);

  return true;
}

void PrintString(String str) {
  // 如果str为空
  if (!str.length) {
    printf_s("(null)");
  }

  for (int i = 0; i < str.length; i++) {
    printf_s("%c", str.buf[i]);
  }
  printf_s("\n");
}

void ClearString(String *s) {
  s->buf = NULL;
  s->length = 0;
}

void DestoryString(String *s) {
  free(s->buf);
  free(s);
}

int strStrWithSimple(String haystack, String needle) {
  // 暴力
  int i = 0;
  int j = 0;

  while (i < haystack.length && j < needle.length) {
    if (haystack.buf[i] == needle.buf[j]) {
      i++;
      j++;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }

  if (j > needle.length - 1) {
    return i - j;
  }

  return -1;
}

void getNext(String patern, int *next) {
  int i = 1;
  int j = 0;

  while (i < patern.length) {
    if (patern.buf[i] == patern.buf[j]) {
      next[i] = j + 1;
      i++;
      j++;
    } else if (j > 0) {
      j = next[j - 1];
    } else {
      // j == 0
      i++;
    }
  }
}

int strStr(String haystack, String needle) {
  int next[100] = {0};

  getNext(needle, next);

  // 打印next数组
  for(int i = 0; i < 100; i ++){
    printf_s("%d ", next[i]);
  }
  printf("\n");

  int i = 0;
  int j = 0;
  while (i < haystack.length && j < needle.length) {
    if (haystack.buf[i] == needle.buf[j]) {
      i++;
      j++;
    } else if (j > 0) {
      j = next[j - 1];
    } else {
      // j == 0
      i++;
    }
  }

  if (j  == needle.length) {
    return i - j;
  }

  return -1;
}

int Index(String haystack, String needle) { return strStr(haystack, needle); }
