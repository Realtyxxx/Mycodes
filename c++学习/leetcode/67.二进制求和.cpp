/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (54.37%)
 * Likes:    503
 * Dislikes: 0
 * Total Accepted:    132.2K
 * Total Submissions: 243K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 *
 * 输入为 非空 字符串且只包含数字 1 和 0。
 *
 *
 *
 * 示例 1:
 *
 * 输入: a = "11", b = "1"
 * 输出: "100"
 *
 * 示例 2:
 *
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 *
 *
 *
 * 提示：
 *
 *
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 *
 *
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n = max(a.size(), b.size()), carry = 0;
    for (int i = 0; i < n; ++i) {
      carry += i < a.size() ? (a[i] == '1') : 0;
      carry += i < b.size() ? (b[i] == '1') : 0;
      ans.push_back((carry % 2) ? '1' : '0');
      carry /= 2;
    }
    if (carry) {
      ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
