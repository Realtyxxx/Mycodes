#include <iostream>
using namespace std;
int main() {
  int n, m, L, temp;
  int i = 0;
  int h[257] = {0};

  cin >> n >> m >> L;
  for (int i = 0; i < n * m; i++) {
    cin >> temp;
    h[temp]++;
  }
  for (; i < L; i++) cout << h[i] << " ";
  return 0;
}