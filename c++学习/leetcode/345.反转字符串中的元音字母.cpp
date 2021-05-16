/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (51.74%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    69.7K
 * Total Submissions: 134.6K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 *
 *
 *
 * 示例 1：
 *
 * 输入："hello"
 * 输出："holle"
 *
 *
 * 示例 2：
 *
 * 输入："leetcode"
 * 输出："leotcede"
 *
 *
 *
 * 提示：
 *
 *
 * 元音字母不包含字母 "y" 。
 *
 *
 */

// @lc code=start
// a e i o u
#include <string>
using namespace std;
class Solution {
 public:
  bool inline isVowels(char a) {
    return (a == 'a' || a == 'i' || a == 'o' || a == 'e' || a == 'u' ||
            a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
  }
  string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (!isVowels(s[left]) && left < right) left++;
      if (!isVowels(s[right]) && left < right) right--;
      if (isVowels(s[left]) && isVowels(s[right]) && left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
      }
    }
    return s;
  }
};
// @lc code=end
