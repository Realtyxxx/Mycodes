#include <iostream>
#include <vector>
using namespace std;

#ifndef ___PRINT_VEC___
#define ___PRINT_VEC___

void printVec(vector<int>& nums, int low, int high) {
  for (int i = low; i <= high; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

void printVec(vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

#endif