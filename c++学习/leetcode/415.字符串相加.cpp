/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (51.83%)
 * Likes:    270
 * Dislikes: 0
 * Total Accepted:    80.8K
 * Total Submissions: 155.8K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 *
 *
 *
 * 提示：
 *
 *
 * num1 和num2 的长度都小于 5100
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
 *
 *
 */

// @lc code=start
class Solution {
public:
  string addStrings(string num1, string num2) {
    int i = num1.size(), j = num2.size(), cur = 0;
    string str;
    while (i > 0 || j > 0 || cur != 0) {
      if (i > 0)
        cur += num1[--i] - '0';
      if (j > 0)
        cur += num2[--j] - '0';
      str += ('0' + cur % 10);
      cur /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
  }
};
// @lc code=end
