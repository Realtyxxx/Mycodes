#include <ctime>
#include <iostream>

using namespace std;
int main() {
  int i, j;
  int A[1024][1024];
  clock_t start = clock();
  // do something...// 程序编写方法1
  for (j = 0; j < 1024; j++) {
    for (i = 0; i < 1024; i++) {
      A[i][j] = 0;
    }
  }

  clock_t end = clock();
  cout << "花费了" << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "毫秒"
       << endl;

  // 程序编写方法2
  clock_t start2 = clock();
  for (i = 0; i < 1024; i++) {
    for (j = 0; j < 1024; j++) {
      A[i][j] = 0;
    }
    // do something...// 程序编写方法1
  }

  clock_t end2 = clock();
  cout << "花费了" << (double)(end2 - start2) / CLOCKS_PER_SEC * 1000 << "毫秒"
       << endl;
  return 0;
}