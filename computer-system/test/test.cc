#include <iostream>
using namespace std;
int a[100];

void fun(int[], int);

int main() {
  fun(a, 5);
  return 0;
}

void fun(int a[], int n) {
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int K = 1;
  for (int i = 1; i <= n; ++i) {
    if (i > 1 && 
		a[i] < a[i - 1]) 
		K = i;
    while (K < n && 
		a[i] >= a[K + 1]) 
		++K;
    cout << K;
  }
}