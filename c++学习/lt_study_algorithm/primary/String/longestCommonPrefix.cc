// 最长公共前缀
// Write a function to find the longest common prefix string amongst an array of
// strings.

// If there is no common prefix, return an empty string "".

//  

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//  

// Constraints:

// 0 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.
// 相关标签
// 字符串

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnmav1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) return strs[0];
    if (strs.size() == 0) return "";
    int p, minSize = strs[0].size();
    for (int i = 1; i < strs.size(); ++i) {
      if (strs[i].size() < minSize) {
        minSize = strs[i].size();
        p = i;
      }
    }
    int count = 0;
    bool equalFlag = true;
    while (count < minSize && equalFlag) {
      char comp = strs[0][count];
      equalFlag = true;
      for (int i = 1; i < strs.size(); ++i) {
        if (strs[i][count] != comp) {
          equalFlag = false;
          break;
        }
      }
      count++;
			if(count == minSize && equalFlag) return  strs[p];
    }
    return count > 1 ?  strs[p].substr(0, count - 1): "";
  }
};

int main() {
  vector<string> strs;
  string str;
  int size;
  cin >> size;
  for (int i = 0; i < size; i++) {
    cin >> str;
    strs.push_back(str);
  }
  Solution tyx;
  cout << tyx.longestCommonPrefix(strs);
  return 0;
}