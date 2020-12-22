// 字符串中的第一个唯一字符
// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

//  

// 示例：

// s = "leetcode"
// 返回 0

// s = "loveleetcode"
// 返回 2
//  

// 提示：你可以假定该字符串只包含小写字母。

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xn5z8r/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    if (s.empty()) return -1;
    if (s.size() == 1) return 0;
    int hashmap[256] = {0};
    for (int i = 0; i < s.size(); i++) {
      hashmap[s[i]] += 1;
    }
    for (int i = 0; i < s.size(); i++) {
      if (hashmap[s[i]] == 1) return i;
    }
    return -1;
  }
};


int main() {
  string input;
  cin >> input;
  Solution tyx;
  cout << tyx.firstUniqChar(input)<<endl;
  return 0;
}