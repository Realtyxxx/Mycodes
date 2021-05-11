/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 *
 * https://leetcode-cn.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (64.30%)
 * Likes:    406
 * Dislikes: 0
 * Total Accepted:    114.5K
 * Total Submissions: 178.1K
 * Testcase Example:  '3'
 *
 * 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
 *
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27
 * 写做  XXVII, 即为 XX + V + II 。
 *
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4
 * 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1
 * 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 *
 *
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 *
 *
 * 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
 *
 * 示例 1:
 *
 * 输入: 3
 * 输出: "III"
 *
 * 示例 2:
 *
 * 输入: 4
 * 输出: "IV"
 *
 * 示例 3:
 *
 * 输入: 9
 * 输出: "IX"
 *
 * 示例 4:
 *
 * 输入: 58
 * 输出: "LVIII"
 * 解释: L = 50, V = 5, III = 3.
 *
 *
 * 示例 5:
 *
 * 输入: 1994
 * 输出: "MCMXCIV"
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 *
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string ans;
    int divisor;

    divisor = num / 1000;
    num %= 1000;
    if (divisor)
      for (int i = 0; i < divisor; i++) {
        ans += 'M';
      }

    divisor = num / 900;
    num %= 900;
    if (divisor)
      ans += "CM";

    divisor = num / 500;
    num %= 500;
    if (divisor)
      for (int i = 0; i < divisor; i++) {
        ans += 'D';
      }

    divisor = num / 400;
    num %= 400;
    if (divisor)
      ans += "CD";

    divisor = num / 100;
    num %= 100;
    if (divisor)
      for (int i = 0; i < divisor; i++) {
        ans += 'C';
      }

    divisor = num / 90;
    num %= 90;
    if (divisor)
      ans += "XC";

    divisor = num / 50;
    num %= 50;
    if (divisor)
      ans += 'L';

    divisor = num / 40;
    num %= 40;
    if (divisor)
      ans += "XL";

    divisor = num / 10;
    num %= 10;
    if (divisor)
      for (int i = 0; i < divisor; i++) {
        ans += 'X';
      }

    divisor = num / 9;
    num %= 9;
    if (divisor)
      ans += "IX";

    divisor = num / 5;
    num %= 5;
    if (divisor)
      ans += 'V';

    divisor = num / 4;
    num %= 4;
    if (divisor)
      ans += "IV";

    divisor = num / 1;
    num %= 1;
    if (divisor)
      for (int i = 0; i < divisor; i++) {
        ans += 'I';
      }

    return ans;
  }
};
// @lc code=end
