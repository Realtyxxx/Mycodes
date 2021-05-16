#include <iostream>
#include <vector>

using namespace std;
#ifndef ___HEAP_SORT___
#define ___HEAP_SORT___
void inline swap(vector<int>& nums, int left, int right) {
  int temp = nums[left];
  nums[left] = nums[right];
  nums[right] = temp;
}

void downShift(vector<int>& nums, int length, int idx) {
  while (true) {
    if (2 * idx >= length - 1) break;
    int leftSon = INT8_MIN, rightSon = INT8_MIN;
    if (2 * idx + 1 < length) leftSon = nums[idx * 2 + 1];
    if (2 * idx + 2 < length) rightSon = nums[idx * 2 + 2];
    int swapidx = leftSon > rightSon ? (idx * 2 + 1) : (idx * 2 + 2);
    if (nums[idx] < nums[swapidx]) {
      swap(nums, idx, swapidx);
    }
    idx = swapidx;
  }
}

void makeHeap(vector<int>& nums, int length) {
  for (int i = length / 2 - 1; i >= 0; i--) {
    downShift(nums, length, i);
  }
}

void heapSort(vector<int>& nums) {
  for (int i = nums.size(); i >= 1;) {
    makeHeap(nums, i);
    swap(nums, 0, --i);
  }
}

#endif