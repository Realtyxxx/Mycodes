/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (63.28%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    188.9K
 * Total Submissions: 298.2K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int s_hash[26] = {0}, t_hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != t[i]) {
        s_hash[s[i] - 'a']++;
        t_hash[t[i] - 'a']++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (s_hash[i] != t_hash[i]) return false;
    }
    return true;
  }
};
// @lc code=end

