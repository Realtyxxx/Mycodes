// 外观数列
// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

// For example, the saying and conversion for digit string "3322251":


// Given a positive integer n, return the nth term of the count-and-say sequence.

//  

// Example 1:

// Input: n = 1
// Output: "1"
// Explanation: This is the base case.
// Example 2:

// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
//  

// Constraints:

// 1 <= n <= 30
// 相关标签
// 字符串

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnpvdm/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
      string ans = "1";
      while(--n) {
        string temp = "";
        int count = 1;
        for(int i = 0; i < ans.length(); i++) {
          if(i != 0 && ans[i] != ans[i-1]) {
            temp += count +'0';
            temp += ans[i - 1];
            count = 1;
          } 
          if(i != 0 && ans[i] == ans[i-1]) {
            count++;
          }
          if(i + 1 == ans.size()) {
            temp += count +'0';
            temp += ans[i];
          }
        }
        ans = temp;
      }
      return ans;
    }
};


int main() {
  Solution my;
  int count = 0;
  cin >> count;
  cout << my.countAndSay(count) << endl;
  return 0;
}