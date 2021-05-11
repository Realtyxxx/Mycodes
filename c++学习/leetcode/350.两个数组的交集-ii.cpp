/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (53.21%)
 * Likes:    424
 * Dislikes: 0
 * Total Accepted:    158.9K
 * Total Submissions: 297.1K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2,2]
 *
 *
 * 示例 2:
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[4,9]
 *
 *
 *
 * 说明：
 *
 *
 * 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
 * 我们可以不考虑输出结果的顺序。
 *
 *
 * 进阶：
 *
 *
 * 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
 * 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>

#include <map>
using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    int l1 = nums1.size(), l2 = nums2.size();
    if (l1 == 0 || l2 == 0)
      return {};

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> ans;

    int left = 0;

    for (int i = 0; i < l1; ++i) {
      int refer = nums1[i], count1 = 1;
      while (i < l1 - 1 && nums1[i] == nums1[i + 1]) {
        i++;
        count1++;
      }
      for (; left < l2;) {
        if (nums2[left] > refer)
          break;

        else if (nums2[left] < refer && left < l2) {
          ++left;
          continue;
        }

        int count2 = 0;
        while (left < l2 && nums2[left] == refer) {
          left++;
          count2++;
        }
        int count = min(count1, count2);
        while (count--) {
          ans.push_back(refer);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
