#include <stdio.h>
int main() {
  int i, j;
  int A[1024][1024];
  // do something...// 程序编写方法1
  for (j = 0; j < 1024; j++) {
    for (i = 0; i < 1024; i++) {
      A[i][j] = i + j;
    }
  }

  // 程序编写方法2

  for (i = 0; i < 1024; i++) {
    for (j = 0; j < 1024; j++) {
      A[i][j] = i + j;
    }
    // do something...// 程序编写方法1
  }
  return 0;
}