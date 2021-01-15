/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.00%)
 * Likes:    953
 * Dislikes: 0
 * Total Accepted:    206.4K
 * Total Submissions: 268K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 *
 * 示例:
 *
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 */
#include <bits/stdc++.h>

#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > res;
    traceback(res, nums, 0, nums.size());
    return res;
  }
  void traceback(vector<vector<int> >& res, vector<int>& outputs, int target,
                 int len) {
    if (target == len) {
      res.emplace_back(outputs);
    }
    for (int i = target; i < len; ++i) {
      swap(outputs[i], outputs[target]);
      traceback(res, outputs, target + 1, len);
      swap(outputs[target], outputs[i]);
    }
  }
};
// @lc code=end
