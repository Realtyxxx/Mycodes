// #include "staticLinkedList.h"
#include<stdio.h>
#define maxSize 6

typedef struct {
  int data;
  int cur;
} component;

//创建备用链表
void reserveArr(component *array) {
  int i = 0;
  for (int i = 0; i < maxSize; i++) {
    array[i].cur = i + 1;
    array[i].data = 0;
  }
  array[maxSize - 1].cur = 0;
}

//提取分配空间
int mallocArr(component *array) {
  //若备用链表非空，则返回分配到节点下标，否则返回0；（当分配最后一个节点时，该节点到游标值为0）
  int i = array[0].cur;
  if (array[0].cur) {
    array[0].cur = array[i].cur;
  }
  return i;
}

//初始化静态链表
int initArr(component *array) {
  int tempBody = 0, body = 0;
  int i = 0;
  reserveArr(array);
  body = mallocArr(array);
  //建立首元节点
  array[body].data = 1;
  array[body].cur = 0;
  //声明一个变量，把它当指针使，指向链表的最后一个节点，当前和首元节点重合
  tempBody = body;
  for (int i = 2; i < 4; i++) {
    int j = mallocArr(array);  //从备用链表中拿出空闲到分量
    array[j].data = i;         //初始化新得到到空间节点
    array[tempBody].cur = j;  //将新得到到节点连接到数据链表到尾部
    tempBody = j;             //将指向最后一个节点到指针后移
  }
  array[tempBody].cur = 0;  //新的链表最后一个节点到指针设置为0；
  return body;
}

void displayArr(component *array, int body) {
  int tempBody = body;
  while (array[tempBody].cur) {
    printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
    tempBody = array[tempBody].cur;
  }
  printf("%d,%d", array[tempBody].data, array[tempBody].cur);
}