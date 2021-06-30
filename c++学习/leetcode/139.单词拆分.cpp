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

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int                   n = s.size();
    unordered_set<string> hs;
    for (auto word : wordDict)
      hs.insert(word);
    if (n == 1 && hs.count(s))
      return true;
    vector<bool> dp(n, false);
    for (int i = 0; i < n; ++i)
      if (i == 0 || dp[i - 1])
        for (int j = i; j < n; ++j) {
          if (i == 0 && hs.count(s.substr(i, j - i + 1))) {
            dp[j] = true;
          } else if (hs.count(s.substr(i, j - i + 1)) && dp[i - 1]) {
            dp[j] = true;
          }
        }
    return dp[n - 1];
  }
};
// @lc code=end
