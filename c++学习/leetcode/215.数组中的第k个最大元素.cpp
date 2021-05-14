/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.43%)
 * Likes:    799
 * Dislikes: 0
 * Total Accepted:    226.9K
 * Total Submissions: 351.8K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k
 * 个最大的元素，而不是第 k 个不同的元素。
 *
 * 示例 1:
 *
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 *
 * 说明:
 *
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 *
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

//快速排序
/* class Solution {
 public:
  int Find(vector<int>& nums, int low, int high, int k) {           //k存储的是找到low到high当中第k小
    if (low == high) return nums[low];                              //如果low==high也就是正好遇到了最坏情况，每次下标刚好错过，
    int  randInList = RandPartion(nums, low, high);                 //randInList存储这次划分的pivot的位置
    int rand = randInList - low + 1;                                //rand就是randInList在这次划分后处于的相对位置
    if (k == rand) return nums[randInList];                         //如果k = rand那么刚好找到了，返回这个位置的值
    else if(rand > k) return Find(nums,low,randInList - 1, k);      //如果k < rand那么第k小的数字就处于low到randInList-1中，此时他还是子序列的第k小的数字
    else return Find(nums,randInList + 1, high, k - rand);          //否则k > rand第k小的数字处于子序列randInList到high之间，此时他是下一个序列的k-randInList小的数字
  }

  int RandPartion(vector<int>& nums, int low, int high) {           //具体的划分序列的函数，返回pivot所在位置，划分称为 <= x : x : >= x
    int pivot = nums[low];                                          //取第一个数为pivot初值，易于处理
    while (low < high) {
      while (high > low && nums[high] >= pivot) --high;             //把末尾所有大于x的排除
      nums[low] = nums[high];                                       //碰到的第一个大于小于x的数存放在pivot的位置，即筛选
      while (low < high && nums[low] <= pivot) ++low;               //排除所有小于等于x的数，即缩小边界，直到碰到第一个大于x的数字，数字下标即为low
      nums[high] = nums[low];                                       //将low位置上大于x得数放到high位置上，此时low位置上存的大于x得数会被下一个循环中的nums[high]替换
    }
    nums[low] = pivot;                                              //将pivot放到pivot属于的位置
    return low;
  }

  int findKthLargest(vector<int>& nums, int k) {
      int i =nums.size() - k + 1;
      return Find(nums,0,nums.size() - 1,i);
  }
}; */

class Solution {
public:
    int randPartion(vector<int>&nums, int low, int high){
        int pivot = nums[low];
        while(low < high){
            while (low < high && nums[high] >= pivot) --high;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) ++low;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }

    int Find(vector<int>& nums, int low, int high, int idx){
        if(low == high) return nums[low];
        int randInList = randPartion(nums, low, high);
        if (randInList == idx) return nums[randInList];
        else if( randInList < idx) return Find(nums, randInList + 1, high, idx);
        else return Find(nums, low, high - 1, idx);
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0];
        int idx = nums.size() - k;
        return Find(nums, 0, nums.size() - 1, idx);
    }
};
// @lc code=end