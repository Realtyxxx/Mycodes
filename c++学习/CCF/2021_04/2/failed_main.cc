#include <iostream>
using namespace std;

#define _B(i, j) b[i][j];

int b[600][600];

int B(int i, int j) {
  if (i < 0 && j < 0)
    return 0;
  else
    return _B(i, j);
}

int main() {
  int n, L, r, t, count = 0;
  cin >> n >> L >> r >> t;
  int a[n][n], c[n][n];
  float d[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (j == 0)
        b[i][j] = a[i][j];
      else
        b[i][j] = a[i][j] + b[i][j - 1];
    }
  }
  for (int j = 0; j < n; j++) {
    for (int i = 1; i < n; i++) {
      b[i][j] += b[i - 1][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int mi = (i - r < 0 ? 0 : i - r), mj = (j - r < 0 ? 0 : j - r);
      int ni = (i + r >= n ? n - 1 : i + r), nj = (j + r >= n ? n - 1 : j + r);

      c[i][j] = b[ni][nj] + B((mi - 1), (mj - 1)) - B(ni, (mj - 1)) - B((mi - 1), nj);
      // d[i][j] = (float)c[i][j] / ((ni - mi + 1) * (nj - mj + 1));

      /*
            cout << "i , j :" << i << " " << j << endl;
            cout << "mi , mj :" << mi << " " << mj << endl;
            cout << "ni , nj :" << ni << " " << nj << endl;
            cout << "b[i][j]: " << b[i][j] << endl;
            cout << "b[ni][nj]: " << b[ni][nj] << endl;
            cout << "B((mi - 1), (mj - 1)) :" << B((mi - 1), (mj - 1)) << endl;
            cout << "B(ni, (mj - 1)) :" << B(ni, (mj - 1)) << endl;
            cout << "B((mi - 1), nj) :" << B((mi - 1), nj) << endl;
            cout << "(ni - mi + 1)*(nj -  mj + 1):  " << (ni - mi + 1) * (nj - mj + 1) << endl;
            cout << "c[i][j] = " << c[i][j] << endl;
            cout << "d[i][j] = " << d[i][j] << endl;
            cout << endl;
       */
      // cout << i << ":" << j << " " << c[i][j] << " " << d[i][j] << endl;
      if ((float)c[i][j] / ((ni - mi + 1) * (nj - mj + 1)) <= t) {
        count++;
        // cout << i << " " << j << endl;
      }
    }
  }
  cout << count << endl;
  return 0;
}
