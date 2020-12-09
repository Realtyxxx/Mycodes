// 暴力解法
#include <bits/stdc++.h>

using namespace std;
int trap(vector<int>& height) {
  int ans = 0;
  int size = height.size();
  for (int i = 1; i < size; ++i) {
      int leftmax=0,rightmax=0;
      for(int j=i;j>=0;--j){
          leftmax=max(leftmax,height[j]);
      }
      for(int j=i;j<size;++j){
          rightmax=max(rightmax,height[j]);
      }
      ans+=min(leftmax,rightmax)-height[i];
  }
  return ans;
}
