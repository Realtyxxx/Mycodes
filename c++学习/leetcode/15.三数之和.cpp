/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (28.11%)
 * Likes:    2329
 * Dislikes: 0
 * Total Accepted:    266.4K
 * Total Submissions: 939.5K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c
 * ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例：
 *
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 *
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int first = 0; first < nums.size(); ++first) {
      if (first != 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      int third = n - 1;
      int target = -nums[first];
      for (int second = first + 1; second < n; ++second) {
        if (second > first + 1 && nums[second] == nums[second - 1]) {
          continue;
        }
        while (second < third && nums[second] + nums[third] > target) {
          --third;
        }
        if (second == third) {
          break;
        }
        if (nums[second] + nums[third] == target) {
          ans.push_back({nums[first], nums[second], nums[third]});
        }
      }
    }
    return ans;
  }
};
// @lc code=end
