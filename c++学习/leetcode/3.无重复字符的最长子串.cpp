/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (35.81%)
 * Likes:    4626
 * Dislikes: 0
 * Total Accepted:    737K
 * Total Submissions: 2.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 * 示例 4:
 *
 *
 * 输入: s = ""
 * 输出: 0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * s 由英文字母、数字、符号和空格组成
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.empty()) return 0;
    if (s.size() == 1) return 1;
    int         hash[256];
    vector<int> dp(s.size() + 1);
    dp[0]   = 1;
    int ans = 1;
    memset(hash, -1, sizeof(hash));
    hash[s[0]] = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (hash[s[i]] == -1) {
        hash[s[i]] = i;
        dp[i]      = dp[i - 1] + 1;
      } else {
        dp[i]      = min(i - hash[s[i]], dp[i - 1] + 1);
        hash[s[i]] = i;
      }
      ans = max(ans, max(dp[i - 1], dp[i]));
      //   "cout << i << ':' << dp[i] <<" s[i] : "<<s[i]<< " hash[s[i]] :
      //   "<<hash[s[i]] << ' ' << "ans: << ans << endl;
    }
    return ans;
  }
};
// @lc code=end
