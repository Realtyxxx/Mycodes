/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (52.75%)
 * Likes:    1731
 * Dislikes: 0
 * Total Accepted:    154.9K
 * Total Submissions: 293.5K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1
 * 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 *
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6
 * 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
 *
 * 示例:
 *
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() == 0)
      return 0;
    int ans = 0, size = height.size();
    vector<int> leftmax(size), rightmax(size);
    leftmax[0] = height[0];
    rightmax[size - 1] = height[size - 1];
    for (int i = 1; i < size; ++i) {
      leftmax[i] = max(leftmax[i - 1], height[i]);
    }
    for (int i = size - 2; i >= 0; --i) {
      rightmax[i] = max(rightmax[i + 1], height[i]);
    }
    for (int i = 0; i < size; ++i) {
      ans += min(leftmax[i], rightmax[i]) - height[i];
    }
    return ans;
  }
};
// @lc code=end
