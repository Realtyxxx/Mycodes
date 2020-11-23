#include <bits/stdc++.h>
using namespace std;

int Partition(int A[], int low, int high) {
  int pivot = A[low];
  while (low < high) {
    while (low < high && A[high] >= pivot) {
      --high;
    }
    A[low] = A[high];
    while (low < high && A[low] <= pivot) {
      ++low;
    }
    A[high] = A[low];
  }
  A[low] = pivot;
  return low;
}

void QuickSort(int A[], int low, int high) {
  if (low < high) {
    int pivot = Partition(A, low, high);
    QuickSort(A, low, pivot - 1);
    QuickSort(A, pivot + 1, high);
  }
}

int main() {
  int a[] = {34, 123, 5432, 1234, 132, 54, 67, 5, 324, 124};
  int count = 0;
  for (auto item : a) count++;
  QuickSort(a, 0, count); 
  for (auto item : a) cout<<item<<" ";
  return 0;
}