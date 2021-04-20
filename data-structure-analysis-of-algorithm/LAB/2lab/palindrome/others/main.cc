
#include <iostream>

#include "LList.h"
#include "list.h"

using namespace std;

int main() {
  int n;
  LList<int> L1(2000);
  LList<int> L2(2000);
  bool f = true;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    L1.append(s[i]);
  }
  for (int i = s.length() - 1; i >= 0; i--) {
    L2.append(s[i]);
  }
  n = L1.length();
  for (int i = 0; i < n; i++) {
    L1.moveToPos(i);
    L2.moveToPos(i);
    if (L1.getValue() != L2.getValue()) {
      // cout << "L1:" << L1.getValue() << "L2:" << L2.getValue() << endl;
      f = false;
      break;
    }
  }

  cout << (f ? "yes" : "no");
  return 0;
}