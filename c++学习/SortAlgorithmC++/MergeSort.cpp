#include "head.h"

void Merge(vector<int> &a, int p, int q, int r) {
  vector<int> b;
  int i = p, j = q + 1;
  while (i <= q && j <= r) {
    if (a[i] <= a[j]) {
      b.push_back(a[i]);
      ++i;
    } else {
      b.push_back(a[j]);
      ++j;
    }
  }
  while (i <= q) {
    b.push_back(a[i]);
    ++i;
  }
  while (j <= r) {
    b.push_back(a[i]);
    ++j;
  }

  for (int k = 0; k < r - p + 1; ++k) {
    a[k + p] = b[k];
  }
}

void MergeSort(vector<int> &a, int p, int r) {
  int q;
  if (p < r) {
    q = (p + r) / 2;
    MergeSort(a, p, q);
    MergeSort(a, q + 1, r);
    Merge(a, p, q, r);
  }
}

int main() {
  vector<int> a;
  a.push_back(5);
  a.push_back(2);
  a.push_back(4);
  a.push_back(3);
  a.push_back(1);
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
  cout << "-----after sort---------";
  cout << endl;
  MergeSort(a, 0, a.size() - 1);
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
  return 0;
}

//递归树层数(lgn+1),n个问题项，每个问题代价为c 所以最终为cnlgn+cn