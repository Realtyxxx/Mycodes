/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.51%)
 * Likes:    893
 * Dislikes: 0
 * Total Accepted:    284.2K
 * Total Submissions: 447.5K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0
 * 移动到数组的末尾，同时保持非零元素的相对顺序。
 *
 * 示例:
 *
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 *
 * 说明:
 *
 *
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int pos = 0;
    for(auto num:nums){
        if(num != 0)
            nums[pos++]=num;
    }
    memset(&nums[pos], 0, sizeof(int) * (nums.size() - pos  ));
    // for(;pos<nums.size();++pos){
    //     nums[pos] = 0;
    // }
  }
};
// @lc code=end
