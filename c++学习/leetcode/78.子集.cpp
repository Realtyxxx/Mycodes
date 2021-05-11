/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.09%)
 * Likes:    859
 * Dislikes: 0
 * Total Accepted:    165.6K
 * Total Submissions: 209.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 *
 * 说明：解集不能包含重复的子集。
 *
 * 示例:
 *
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
int n;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    n = nums.size();
    vector<int> cur;
    for (int k = 0; k <= n; ++k) {
      traceback(0, k, res, nums, cur);
    }
    return res;
  }
  void traceback(int start, int k, vector<vector<int>> &res, vector<int> &nums,
                 vector<int> &cur) {
    if (k == 0) {
      res.push_back(cur);
      return;
    }
    for (int i = start; i < n; ++i) {
      cur.push_back(nums[i]);
      traceback(i + 1, k - 1, res, nums, cur);
      cur.pop_back();
    }
  }
};
// @lc code=end
