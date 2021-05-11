/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode-cn.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (31.42%)
 * Likes:    539
 * Dislikes: 0
 * Total Accepted:    55K
 * Total Submissions: 174.9K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p)
 * ，实现一个支持 '?' 和 '*' 的通配符匹配。
 *
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 *
 *
 * 两个字符串完全匹配才算匹配成功。
 *
 * 说明:
 *
 *
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 *
 *
 * 示例 1:
 *
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 *
 * 示例 2:
 *
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 *
 *
 * 示例 3:
 *
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 *
 *
 * 示例 4:
 *
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 *
 *
 * 示例 5:
 *
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输出: false
 *
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      if (p[i - 1] == '*') {
        dp[0][i] = true;
      } else {
        break;
      }
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
        } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }
    return dp.back().back();
  }
};
// @lc code=end
