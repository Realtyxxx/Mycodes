#include <algorithm>
#include <iostream>
using namespace std;

inline int findpivot(int *A, int i, int j) {
  cout << "pivot :" << (i + j) / 2 << " ";
  return (i + j) / 2;
}
inline int Partition(int *A, int left, int right, int &pivot) {
  do {
    while (A[++left] < pivot)
      ;
    while ((left < right) && (pivot < A[--right]))
      ;
    swap(A[left], A[right]);
  } while (left < right);
  cout << left << ":" << A[left] << endl;
  return left;
}
int size;

void qsort(int *A, int left, int right) {
  if (left >= right) return;
  int pivotindex = findpivot(A, left, right);
  // swap(A,pivotindex,);
  int temp = A[right];
  A[right] = A[pivotindex];
  A[pivotindex] = temp;
  int k = Partition(A, left - 1, right, A[right]);
  // swap(A, k, right);
  temp = A[right];
  A[right] = A[k];
  A[k] = temp;
  qsort(A, left, k - 1);
  qsort(A, k + 1, right);
}
int main() {
  int n;
  scanf("%d", &n);
  int *a;
  a = new int[n];
  size = n;
  for (int i = 0; i < n; i++) cin >> a[i];

  qsort(a, 0, n - 1);

  for (int i = 0; i < n; i++) cout << a[i] << "  ";
  cout << endl;
  return 0;
}
/*
24
2 342 45 94 03 9 48 93 03 84 93 44 99 023 32 43 5 332 32 85 84 95 99 32 23

 */