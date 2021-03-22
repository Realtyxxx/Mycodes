#include <stdio.h>
#include "staticLinkedList.h"

#define maxSize 6

int main() {
  component array[maxSize];
  int body = initArr(array);
  printf("静态链表： \n");
  displayArr(array, body);
  return 0;
}