#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int>& nums, int low, int high) {
  for (int i = low; i <= high; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}


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
  printVec(nums, low, high);    //输出
  quickSort(nums, low, pivot);
  if (pivot < high) quickSort(nums, pivot + 1, high);
}

int main() {
  vector<int> myVec;
  myVec.push_back(31);
  myVec.push_back(73);
  myVec.push_back(44);
  myVec.push_back(13);
  myVec.push_back(7);
  myVec.push_back(28);
  myVec.push_back(22);
  myVec.push_back(64);
  myVec.push_back(53);
  printVec(myVec, 0, myVec.size() - 1);
  quickSort(myVec, 0, myVec.size() - 1);
  return 0;
}