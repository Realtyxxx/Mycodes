#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool include(int x, int base) {
  string targetStr = to_string(x);
  string baseStr   = to_string(base);
  int    tarLen    = targetStr.length();
  int    len       = baseStr.length();
  for (int i = (tarLen - len); i >= 0; i--) {
    // cout << targetStr.substr(i, len) << endl;
    if (targetStr.substr(i, len) == baseStr)
      return true;
  }
  return false;
}

int main() {
  int barrier, base;
  cin >> barrier >> base;
  // vector<int> ans;
  // cout << include(barrier, base) << endl;
  for (int i = 1; i <= barrier; i++) {
    if ((i % base == 0) || include(i, base)) {
      // ans.push_back(i);
      cout << i << " ";
    }
  }
  // for (auto a : ans)
  // cout << a << " ";
  return 0;
}