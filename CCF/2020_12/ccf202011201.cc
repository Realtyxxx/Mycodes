#include <iostream>
using namespace std;
int main() {
  int n, w_value, score, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> w_value >> score;
    res += w_value * score;
  }
  res = res > 0 ? res : 0;
  cout << res << endl;
  return 0;
}
