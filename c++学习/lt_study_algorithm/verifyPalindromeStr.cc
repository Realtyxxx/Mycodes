//

#include <iostream>
#include <string>
using namespace std;

class Solution1 {
 public:
  bool isPalindrome(string s) {
    string s1, s2;
    for (auto e : s) {
      if ((e <= 'Z' && e >= 'A') || (e >= 'a' && e <= 'z') ||
          (e >= '0' && e <= '9')) {
        if (e <= 'Z' && e >= 'A') e += 32;
        s1 += e;
      }
    }
    for (int i = s1.size() - 1; i >= 0; i--) {
      s2 += s1[i];
    }
    // cout << s1 << endl;
    // cout << s2 << endl;

    if (s1 == s2)
      return true;
    else
      return false;
  }
};

class Solution {
 public:
  bool isPalindrome(string s) {
    int i = 0, j = 0;
    for (; i < s.size(); i++) {
      if ((s[i] <= 'Z' && s[i] >= 'A') || (s[i] >= 'a' && s[i] <= 'z') ||
          (s[i] >= '0' && s[i] <= '9')) {
        if (s[i] <= 'Z' && s[i] >= 'A') s[i] += 32;
        s[j] = s[i];
        j++;
      }
    }
    // s[j] = '\0';
    // cout << s << endl;
    ;
    j--;
    for (i = 0; i <= j; i++, j--) {
      if (s[i] != s[j]) return false;
    }
    return true;
  }
};

int main() {
  Solution res;
  string s = "A man, a plan, a canal: Panama";
  cout << res.isPalindrome(s) << endl;
  string t = "race a car";
  cout << res.isPalindrome(t) << endl;
  return 0;
}