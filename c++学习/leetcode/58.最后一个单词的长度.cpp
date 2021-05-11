/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (33.70%)
 * Likes:    244
 * Dislikes: 0
 * Total Accepted:    128.5K
 * Total Submissions: 381.2K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串
 * s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 *
 * 如果不存在最后一个单词，请返回 0 。
 *
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 *
 *
 *
 * 示例:
 *
 * 输入: "Hello World"
 * 输出: 5
 *
 *
 */

// @lc code=start
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
  //   bool isLetter(char character) {
  //     if ((character < 'z' && character > 'a') ||
  //         (character > 'A' && character < 'Z')) {
  //       return true;
  //     }
  //     return false;
  //   }
  int lengthOfLastWord(string s) {
    int i = s.length() - 1;
    bool haveWord = false;
    while (s[i] == ' ' && i >= 0)
      i--;
    //   cout<<s.length();
    int right = i;
    while (s[i] != ' ' && i >= 0) {
      i--;
      haveWord = true;
    }
    if (!haveWord)
      return 0;
    return right - i;
  }
};
// @lc code=end
