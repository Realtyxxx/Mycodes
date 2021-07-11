#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int* light = new int[m];

  // for (int i = 0; i < m; i++) {
  //   light[i] = 0;
  // }

  int** a = new int*[n];

  for (int i = 0; i < n; i++) {
    a[i] = new int[m];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j]) {
        light[j]++;
      }
    }
  }
  // light: count how many switch could control this light
  bool isNecessary;
  for (int i = 0; i < n; i++) {
    isNecessary = true;
    for (int j = 0; j < m; j++) {
      if (a[i][j] && light[j] == 1) {
        isNecessary = false;
        break;
      }
    }
    if (!isNecessary)
      break;
  }

  if (!isNecessary)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  for (int i = 0; i < n; i++) {
    delete[] a[i];
  }
  delete[] a;
}
