/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 *
 * https://leetcode-cn.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (79.16%)
 * Likes:    399
 * Dislikes: 0
 * Total Accepted:    109.7K
 * Total Submissions: 138.5K
 * Testcase Example:  '1\n4'
 *
 * 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
 *
 * 给出两个整数 x 和 y，计算它们之间的汉明距离。
 *
 * 注意：
 * 0 ≤ x, y < 2^31.
 *
 * 示例:
 *
 *
 * 输入: x = 1, y = 4
 *
 * 输出: 2
 *
 * 解释:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 *
 * 上面的箭头指出了对应二进制位不同的位置。
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int count = 0;
    while (x != 0 || y != 0) {
      count = ((x & 1) != (y & 1)) ? (count + 1) : count;
      x /= 2;
      y /= 2;
    }
    return count;
  }
};
// @lc code=end
