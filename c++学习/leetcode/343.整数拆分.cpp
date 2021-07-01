/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (59.98%)
 * Likes:    549
 * Dislikes: 0
 * Total Accepted:    92.5K
 * Total Submissions: 154K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。
 * 返回你可以获得的最大乘积。
 *
 * 示例 1:
 *
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 *
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 *
 */
#include <iostream>
#include <vector>

// @lc code=start
class Solution {
 public:
  int integerBreak(int n) {
    if (n <= 2)
      return 1;
    std::vector<int> a(n + 1, 0);
    // a[i]中存储的是数i可以得到的最优解，也因此这个解实际上没有保留它自身
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = i - 1; j >= int(i / 2); j--) {
        //***********方法1:***********
        // a[i] = std::max((i < n ? i : 0), std::max(a[j] * (i - j), a[i]));
        //可以是他自己的乘积或者它的最优子解得到的答案:::::我感觉我暂时没法解释。这个暂时不可取

        //***********方法2***********
        a[i] = std::max(std::max((i < n ? i : 0), a[i - j] * a[j]), a[i]);
        //实际上也是后面理解了前面没有去判断它的的子结构与它自身的大小比较，还需要判断是否比当前的a[i]大

        // std::cout << "a[" << i << "] : " << a[i] << std::endl;
      }
    }
    return a[n];
  }
};
// @lc code=end
