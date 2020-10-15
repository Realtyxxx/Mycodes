#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  string countAndSay(int n) {
    string temp = "1";
    int count = 1;
    while (--n) {
      string mid = "";
      for (int i = 1; i < temp.size(); i++) {
        if (temp[i] == temp[i - 1]) {
          count += 1;
        } else {
          mid += char(count + '0');
          mid += temp[i - 1];
          count = 1;
        }
      }
      mid += '0' + count;
      mid += temp[temp.size() - 1];
    //   cout << mid << " ";
      count=1;
      temp = mid;
    }
    return temp;
  }
};