#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
  if (height.size() == 0) return 0;
  int ans = 0, size = height.size();
  vector<int>leftmax(size),rightmax(size);
  leftmax[0] =height[0];rightmax[size-1] =height[size-1];
  for(int i = 1; i < size;++i) {
      leftmax[i] =max(leftmax[i-1],height[i]);
  }
  for(int i=size-2;i>=0;--i) {
      rightmax[i] =max(rightmax[i+1],height[i]);
  }
  for(int i=0;i<size;++i) {
      ans+=min(leftmax[i],rightmax[i])- height[i];
  }
  return ans;
}
