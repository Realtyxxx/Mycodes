#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
  int ans = 0, current = 0;
  stack<int> st;
  while (current < height.size()) {
    while (!st.empty() && height[current] > st.top()) {
      int top = st.top();
      st.pop();
      if (st.empty()) break;
      int distance = current - st.top() - 1;
      ans += distance * (min(height[current], height[st.top()]) - height[top]);
    }
    st.push(current++);
  }
  return ans;
}
