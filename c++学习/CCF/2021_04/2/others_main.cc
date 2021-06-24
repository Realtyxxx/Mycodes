
#include <bits/stdc++.h>
using namespace std;
int h[605][605], v[605][605], a[605][605];
int main() {
  int n, l, c, t;
  int sum = 0;
  cin >> n >> l >> c >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      h[i][j] = h[i][j - 1] + a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int l = j - c < 1 ? 1 : j - c;
      int r = j + c > n ? n : j + c;
      int u = i - c < 1 ? 1 : i - c;
      int d = i + c > n ? n : i + c;
      double temp = 0;
      for (int k = u; k <= d; k++) {
        temp += (h[k][r] - h[k][l - 1]);
      }
      temp = temp / 1.0 / ((d - u + 1) * (r - l + 1));
      if (temp <= t) sum++;
    }
  }
  cout << sum << endl;
}
// ————————————————
// 版权声明：本文为CSDN博主「jinduo16」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/jinduo16/article/details/116152675