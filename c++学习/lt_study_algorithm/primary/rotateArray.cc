// 旋转数组
// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

// 示例 1:

// 输入: [1,2,3,4,5,6,7] 和 k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右旋转 1 步: [7,1,2,3,4,5,6]
// 向右旋转 2 步: [6,7,1,2,3,4,5]
// 向右旋转 3 步: [5,6,7,1,2,3,4]
// 示例 2:

// 输入: [-1,-100,3,99] 和 k = 2
// 输出: [3,99,-1,-100]
// 解释:
// 向右旋转 1 步: [99,-1,-100,3]
// 向右旋转 2 步: [3,99,-1,-100]
// 说明:

// 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
// 要求使用空间复杂度为 O(1) 的 原地 算法。
// 相关标签
// 数组

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2skh7/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int l = nums.size();
    if (l == 0||l == 1) return;
    k %= l;
    int change;
    while (k--) {
      change = nums[l - 1];
      for (int i = l - 2; i >= 0; i--) nums[i + 1] = nums[i];
      nums[0] = change;
    }
  }
};

class Solution1 {
 public:
  void rotate(vector<int>& nums, int k) {
    int l = nums.size();
    reverse(nums.begin(),nums.end());
    k %= l;
    k = l - k;
    reverse(nums.begin(), nums.begin() + k - 1);
    reverse(nums.begin() + k, nums.end());

  }
};

//[-1,-100,3,99]
// 2