#include <stdio.h>

#include "test.h"  //必须引入头文件

int main(void) {
  int m, n;
  printf("Input two numbers: ");
  scanf("%d %d", &m, &n);
  printf("%d+%d=%d\n", m, n, add(m, n));
  printf("%d-%d=%d\n", m, n, sub(m, n));
  printf("%d÷%d=%d\n", m, n, div(m, n));

  return 0;
}