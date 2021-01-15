/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.49%)
 * Likes:    493
 * Dislikes: 0
 * Total Accepted:    108.6K
 * Total Submissions: 244K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 *
 * 示例 1:
 *
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 *
 * 示例 2:
 *
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 *
 * 说明：
 *
 *
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }
    int m = num1.size(), n = num2.size();
    auto ansArr = vector<int>(m + n);
    for (int i = m - 1; i >= 0; --i) {
      int x = num1.at(i) - '0';
      for (int j = n - 1; j >= 0; --j) {
        int y = num2.at(j) - '0';
        ansArr[i + j + 1] += x * y;
      }
    }
    for (int i = m + n - 1; i > 0; --i) {
      ansArr[i - 1] += ansArr[i] / 10;
      ansArr[i] = ansArr[i] % 10;
    }
    int index = ansArr[0] == 0 ? 1 : 0;
    string ans;
    while (index < m + n) {
      ans.push_back(ansArr[index]);
      index++;
    }
    for (auto &t : ans) {
      t += '0';
    }
    return ans;
  }
};
// @lc code=end
