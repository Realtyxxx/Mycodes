// #include <omp.h>
#include <iostream>
#include <vector>

#include "printVec.h"

using namespace std;

#ifndef ___RADIX_SORT___
#define ___RADIX_SORT___

int maxBit(vector<int>& nums) {
  int length = nums.size(), maxbit = 0, data = 0;
  for (int i = 0; i < length; i++) {
    data = nums[i] >= data ? nums[i] : data;
  }
  while (data) {
    maxbit++;
    data /= 10;
  }
  return maxbit;
}

void radixSort(vector<int>& nums) {
  // cout << "begin radixSort " << endl;
  int length = nums.size();
  int maxbit = maxBit(nums);  //取最高位——>这里我只用它来控制循环次数
  int radix = 1;              //从个位到最高位
  int k;                      //后面用来记录插值位置

  vector<int> temp(length);

  while (maxbit--) {
    vector<int> count(10, 0);
    for (int j = 0; j < length; j++) {
      k = (nums[j] / radix) % 10;
      count[k]++;
    }
    for (int j = 1; j < 10; j++) {
      count[j] = count[j - 1] + count[j];  //统计位置
    }
    for (int j = length - 1; j >= 0; j--) {
      k                  = (nums[j] / radix) % 10;
      temp[count[k] - 1] = nums[j];
      count[k]--;
    }
    nums.swap(temp);
    // printVec(nums);
    radix *= 10;
  }
  // cout << "end radixSort " << endl;
}

#endif
