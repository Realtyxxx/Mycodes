/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> count(nums.size() + 1, 0);
    vector<int> res;
    int i = 0;
    for (; i < nums.size(); ++i) {
      count[nums[i]]++;
    }
    for (i = 0; i < count.size(); ++i) {
      if (count[i] == 2)
        res.push_back(i);
    }
    return res;
  }
};
// @lc code=end
