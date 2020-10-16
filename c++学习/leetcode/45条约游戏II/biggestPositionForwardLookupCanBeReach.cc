#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
  int n = nums.size(), maxPos = 0, end = 0, steps = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (maxPos >= i) {
      maxPos = max(maxPos, i + nums[i]);
      if (i == end) {
        end = maxPos;
        ++steps;
      }
    }
  }

  return steps;
}