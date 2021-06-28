/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (46.68%)
 * Likes:    307
 * Dislikes: 0
 * Total Accepted:    186.9K
 * Total Submissions: 400.1K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 *
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 *
 * 示例 1:
 *
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: "race a car"
 * 输出: false
 *
 *
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isAlphabet(char c) {
    return ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || (c >= '0' && c <= '9'));
  }
  char toSmall(char c) {
    if ((c <= 'Z' && c >= 'A')) {
      return c + 32;
    } else
      return c;
  }
  bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
      if (isAlphabet(s[i]) && isAlphabet(s[j]) && toSmall(s[i]) != toSmall(s[j])) {
        return false;
      }
      if (!isAlphabet(s[i])) {
        i++;
        continue;
      }
      if (!isAlphabet(s[j])) {
        j--;
        continue;
      }
      i++;
      j--;
    }
    return true;
  }
};
// @lc code=end
