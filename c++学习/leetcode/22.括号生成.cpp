/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.20%)
 * Likes:    1304
 * Dislikes: 0
 * Total Accepted:    178.7K
 * Total Submissions: 234.5K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且
 * 有效的 括号组合。
 *
 *
 *
 * 示例：
 *
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 *
 *
 */

// @lc code=start
class Solution {
public:
  void backtrack(vector<string> &ans, string &cur, int open, int close, int n) {
    if (cur.length() == n * 2) {
      ans.push_back(cur);
      return;
    }
    if (open < n) {
      cur.push_back('(');
      backtrack(ans, cur, open + 1, close, n);
      cur.pop_back();
    }
    if (close < open) {
      cur.push_back(')');
      backtrack(ans, cur, open, close + 1, n);
      cur.pop_back();
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    backtrack(result, current, 0, 0, n);
    return result;
  }
};
// @lc code=end
