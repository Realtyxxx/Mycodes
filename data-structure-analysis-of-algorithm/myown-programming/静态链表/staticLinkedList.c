#include <stdio.h>

#define maxSize 6

typedef struct {
  int data;
  int cur;
} component;

//将结构体数组中所有分量链接到备用链表中
void reserveArr(component *array);
//初始化静态链表
int initArr(component *array);
//输出函数
void displayArr(component *array, int body);
//从备用链表上摘下空闲节点到函数
int mallocArr(component *array);



int main() {
  component array[maxSize];
  int body = initArr(array);
  printf("静态链表： \n");
  displayArr(array, body);
  return 0;
}