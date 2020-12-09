#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
  int position = nums.size() - 1;
  int steps = 0;
  while (position > 0) {
    for (int i = 0; i < position; ++i) {
        if(i+nums[i] >=position) {
            position = i;
            steps++;
            break;
        }
    }
  }
  return steps;
}