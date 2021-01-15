/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (34.79%)
 * Likes:    2409
 * Dislikes: 0
 * Total Accepted:    539.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 *
 * 示例 1:
 *
 * 输入: 123
 * 输出: 321
 *
 *
 * 示例 2:
 *
 * 输入: -123
 * 输出: -321
 *
 *
 * 示例 3:
 *
 * 输入: 120
 * 输出: 21
 *
 *
 * 注意:
 *
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 −
 * 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 *
 */

// @lc code=start
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
class Solution {
 public:
  int reverse(int x) {
    if (x == 0) return 0;
    ll ans = 0;
    for (; x >= 1 || x <= -1; x /= 10) {
      if (x < 0 && (ans * 10 <= INT_MIN - x) ||
          x > 0 && (ans * 10 > INT_MAX - x))
        return 0;
      ans = ans * 10 + x % 10;
    }
    return ans;
  }
};
// @lc code=end
