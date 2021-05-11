/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (58.49%)
 * Likes:    1330
 * Dislikes: 0
 * Total Accepted:    511.2K
 * Total Submissions: 872.8K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 示例 1:
 *
 * 输入: 121
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 *
 *
 * 示例 3:
 *
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 *
 *
 * 进阶:
 *
 * 你能不将整数转为字符串来解决这个问题吗？
 *
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    string str = to_string(x);
    int left = 0;
    int right = str.size() - 1;
    while (left < right) {
      if (str[left] != str[right])
        return false;
      ++left;
      --right;
    }
    return true;
  }
};
// @lc code=end
