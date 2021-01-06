#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  inline bool isNume(char c) {
    if ((c < '0' || c > '9')) return false;
    return true;
  }
  int myAtoi(string s) {
    long long ans = 0;
    int i = 0;
    bool sign = true;
    for (; i < s.size() && s[i] == ' '; i++)
      ;
    if (i == s.size()) return 0;
    if (s[i] != '+' && s[i] != '-') {
      i--;
    } else if (s[i] != '+' && s[i] != '-' && !isNume(s[i])) {
      return 0;
    } else {
      if (s[i] == '-') sign = false;
    }
    for (int j = i + 1; j < s.size() && isNume(s[j]); j++) {
      ans = ans * 10 + int(s[j] - '0');
      if (ans > 2147483648) break;
    }
    if (ans > INT_MAX) {
      if (sign) return INT_MAX;
      if (-ans < INT_MIN) {
        if (!sign) return INT_MIN;
      }
    }
    return sign ? ans : -ans;
  }
};

int main() {
  string s;
  cin >> s;
  Solution myans;
  cout << myans.myAtoi(s) << endl;
  return 0;
}