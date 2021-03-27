/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (49.50%)
 * Likes:    812
 * Dislikes: 0
 * Total Accepted:    294.1K
 * Total Submissions: 593.5K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1
 * 成为一个有序数组。
 *
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1
 * 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * 输出：[1,2,2,3,5,6]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1], m = 1, nums2 = [], n = 0
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m + n
 * nums2.length == n
 * 0
 * 1
 * -10^9
 *
 *
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0) return;
    vector<int> temp;
    int i = 0, j = 0;
    for (; i < m && j < n;) {
      if (nums1[i] <= nums2[j]) {
        temp.push_back(nums1[i]);
        i++;
        continue;
      } else {
        temp.push_back(nums2[j]);
        j++;
      }
    }
    while (i < m) {
      temp.push_back(nums1[i]);
      i++;
    }
    while (j < n) {
      temp.push_back(nums2[j]);
      j++;
    }
    nums1 = temp;
    // for(int i = 0; i< temp.size(); i++) cout<<temp[i]<<' ';
    // for(int i = 0; i< nums1.size(); i++) cout<<nums1[i]<<' ';
  }
};
// @lc code=end
