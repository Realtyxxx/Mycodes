#include <iostream>
#include <vector>

using namespace std;

#ifndef __QUICK_SORT__
#define __QUICK_SORT__

int randPartion(vector<int>& nums, int low, int high) {
  int pivot = nums[low];
  while (low < high) {
    while (low < high && nums[high] >= pivot) --high;
    nums[low] = nums[high];
    while (low < high && nums[low] <= pivot) ++low;
    nums[high] = nums[low];
  }
  nums[low] = pivot;
  return low;
}

void quickSort(vector<int>& nums, int low, int high) {
  if (low == high) return;
  int pivot = randPartion(nums, low, high);
  // printVec(nums, low, high);    //输出
  quickSort(nums, low, pivot);
  if (pivot < high) quickSort(nums, pivot + 1, high);
}

void quickSort(vector<int>& nums) { quickSort(nums, 0, nums.size() - 1); }

#endif