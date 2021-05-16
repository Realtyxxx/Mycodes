/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (45.69%)
 * Likes:    632
 * Dislikes: 0
 * Total Accepted:    141.3K
 * Total Submissions: 308K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 *
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ...,
 * numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * 1
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n))
 * 时间复杂度的解法。
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = -1;
    int sum = 0;
    int minLen = nums.size() + 1;
    while (left < nums.size()) {
      if (sum < target && right + 1 < nums.size()) {
        sum += nums[++right];
      } else
        sum -= nums[left++];
      if (sum >= target) minLen = min(minLen, right - left + 1);
    }
    if (minLen == nums.size() + 1) return 0;
    return minLen;
  }
};
// @lc code=end
