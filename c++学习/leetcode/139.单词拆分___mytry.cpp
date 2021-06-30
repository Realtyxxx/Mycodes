/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (50.48%)
 * Likes:    1038
 * Dislikes: 0
 * Total Accepted:    156.7K
 * Total Submissions: 310K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s
 * 是否可以被空格拆分为一个或多个在字典中出现的单词。
 *
 * 说明：
 *
 *
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 *
 *
 * 示例 1：
 *
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 *
 *
 * 示例 2：
 *
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 *
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<bool>> check;
  int                  n;
  bool                 yes;

 public:
  bool inDict(string sub, vector<string>& wordDict) {
    for (auto word : wordDict) {
      if (word == sub)
        return true;
    }
    return false;
  }

  void backTrace(string s, vector<string>& wordDict, int idx) {
    if (idx >= s.size())
      return;
    for (int j = 0; j < s.size(); ++j) {
      // cout << "idx: " << idx << "  j:" << j << "substr: " << s.substr(idx, j + 1) << endl;
      if (inDict(s.substr(idx, j + 1), wordDict)) {
        check[idx][j] = true;
        if (j == n - 1)
          yes = true;
        if (yes)
          return;
        backTrace(s, wordDict, idx + j + 1);
      }
      if (yes)
        return;
    }
  }

  void printCheck() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << check[i][j] << " ";
      }
      cout << endl;
    }
  }
  bool wordBreak(string s, vector<string>& wordDict) {
    n   = s.size();
    yes = false;
    if (n == 1) {
      if (inDict(s, wordDict))
        return true;
      else
        return false;
    }
    check.assign(n, vector<bool>(n, false));
    backTrace(s, wordDict, 0);
    // printCheck();
    for (int i = 0; i < n; i++) {
      if (check[i][n - 1])
        return true;
    }
    return false;
  }
};
// @lc code=end
