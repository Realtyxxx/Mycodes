//all correct

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    int a[10001] = {0};
    int maxNum = 0, idx = 0, maxCnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> idx;
      a[idx]++;
      if (a[idx] > maxCnt) {
        maxCnt = a[idx];
        maxNum = idx;
      }
    }
    cout << maxNum << endl;
  }
}