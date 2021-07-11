#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int realMeter(int x);

int main() {
  vector<int> ans;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int odoMeter = 0;
    cin >> odoMeter;
    ans.push_back(realMeter(odoMeter));
  }
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ans[i] << endl;
  return 0;
}

int realMeter(int x) {
  vector<int> aVector;

  int tmp = x;
  int div = 10;
  int sub = 0;

  while (tmp) {
    aVector.push_back(tmp % div);
    tmp /= div;
  }

  for (int i = 0; i < (int)aVector.size(); i++) {
    int num = aVector[i];
    switch (num) {
      case 0:
        break;
      case 1:
      case 2:
        if (i != 0) {
          sub += num * 2 * pow(10, i - 1);
          for (int k = i - 2; k >= 0; k--) {
            sub += num * pow(8, i - 1 - k) * 2 * pow(10, k);
          }
        }
        break;
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
        if (i == 0) {
          sub += 1;
        } else {
          sub += pow(10, i) + (num - 1) * 2 * pow(10, i - 1);
          for (int k = i - 2; k >= 0; k--) {
            sub += (num - 1) * pow(8, i - 1 - k) * 2 * pow(10, k);
          }
        }
        break;
      case 8:
      case 9:
        if (i == 0) {
          sub += 2;
        } else {
          sub += 2 * pow(10, i) + (num - 2) * 2 * pow(10, i - 1);
          for (int k = i - 2; k >= 0; k--) {
            sub += (num - 2) * pow(8, i - 1 - k) * 2 * pow(10, k);
          }
        }
        break;
    }
  }
  return x - sub;
}