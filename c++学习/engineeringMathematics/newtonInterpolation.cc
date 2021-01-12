#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  float value;
  vector<float> g;
  vector<float> x;
  cout << "number of elements" << endl;
  cin >> n;
  cout << "x values" << endl;
  for (int i = 0; i < n; i++) {
    cin >> value;
    x.push_back(value);
  }
  cout << "y values" << endl;
  for (int i = 0; i < n; i++) {
    cin >> value;
    g.push_back(value);
  }
  cout << "差商" << endl;
  for (int i = 1; i < n; i++) {
    for (int j = n - 1; j >= i; j--) {
      g[j] = (g[j] - g[j - 1]) / (x[j] - x[j - i]);
    }
    for (auto e : g) cout << e << " ";
    cout << endl << "number " << i << " iteration" << endl;
  }
  return 0;
}