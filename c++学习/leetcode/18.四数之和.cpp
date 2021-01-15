/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (39.28%)
 * Likes:    680
 * Dislikes: 0
 * Total Accepted:    138.1K
 * Total Submissions: 350.7K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n
 * 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素
 * a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 *
 * 注意：
 *
 * 答案中不可以包含重复的四元组。
 *
 * 示例：
 *
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 *
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */

// @lc code=start
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 private:
  vector<int> temp;
  vector<vector<int>> ans;
  set<int> numset;

 public:
  void Dfs(vector<int> nums, int low, int need) {
    if (temp.size() == 3) {
      //   cout << "need :" << need << endl;
      if ((numset.count(need) && need > nums[low - 1]) || need == nums[low]) {
        temp.emplace_back(need);
        // for (auto e : temp) cout << e << " ";
        // cout << endl;
        ans.emplace_back(temp);
        temp.pop_back();
      }
      return;
    }
    for (int i = low; i < nums.size(); ++i) {
      if (nums.size() - i < int(4 - temp.size())) return;
      if (i > low && nums[i] == nums[i - 1]) continue;
      if (i < nums.size() - 1 &&
          need < nums[i] + int(3 - temp.size()) * nums[i + 1])
        return;
      if (i < nums.size() - 1 &&
          need > nums[i] + int(3 - temp.size()) * nums[nums.size() - 1])
        continue;
      temp.emplace_back(nums[i]);
      //   for (auto e : temp) cout << e << " ";
      //   cout << endl;
      Dfs(nums, i + 1, need - nums[i]);
      temp.pop_back();
    }
    return;
  }

  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    for (auto e : nums) numset.insert(e);
    Dfs(nums, 0, target);
    return ans;
  }
};
// @lc code=end

// temp.push_back(nums[low]);
// for (auto e : temp) cout << e<< ' ';
// cout <<'|'<<need - nums[low]<< endl;
// Dfs(nums, low + 1, need - nums[low]);
// temp.pop_back();
// Dfs(nums, low + 1, need);