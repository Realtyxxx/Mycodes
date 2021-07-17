#include <iostream>
#include <vector>

using namespace std;
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
  int l       = nums.size();
  int radix   = 1;
  int max_bit = maxBit(nums);

  vector<int> tmp(l);
  vector<int> count(10, 0);
  while (max_bit--) {
    for (int i = 0; i < l; i++) {
      int k = (nums[i] / radix) % 10;
      count[k]++;
    }
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (int i = l - 1; i >= 0; i--) {
      int k             = (nums[i] / radix) % 10;
      tmp[count[k] - 1] = nums[i];
      count[k]--;
    }
    nums.swap(tmp);
    radix *= 10;
  }
}

int main() {
  int         array_length = 10;
  vector<int> myVec(array_length);
  for (int i = 0; i < myVec.size(); i++) {
    myVec[i] = rand() % 1024 + 1;
  }
  for (auto num : myVec) cout << num << " ";
  cout << endl;
  radixSort(myVec);
  for (auto num : myVec) cout << num << " ";
  cout << endl;
  return 0;
}