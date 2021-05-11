/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (40.24%)
 * Likes:    810
 * Dislikes: 0
 * Total Accepted:    92.1K
 * Total Submissions: 228.7K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
 *
 *
 *
 * 示例 1:
 *
 * 输入: [1,2,0]
 * 输出: 3
 *
 *
 * 示例 2:
 *
 * 输入: [3,4,-1,1]
 * 输出: 2
 *
 *
 * 示例 3:
 *
 * 输入: [7,8,9,11,12]
 * 输出: 1
 *
 *
 *
 *
 * 提示：
 *
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
 *
 */

// @lc code=start
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int l = nums.size();
    for (int i = 0; i < l; ++i) {
      if (nums[i] <= 0) {
        nums[i] = l + 1;
      }
    }
    for (int i = 0; i < l; ++i) {
      int num = abs(nums[i]);
      if (num <= l) {
        nums[num - 1] = -abs(nums[num - 1]);
      }
    }
    for (int i = 0; i < l; ++i) {
      if (nums[i] >= 0)
        return i + 1;
    }
    return l + 1;
  }
};
// @lc code=end
