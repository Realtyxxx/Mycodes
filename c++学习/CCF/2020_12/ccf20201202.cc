#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

const int N = 1e6 + 100;
typedef long long ll;
typedef pair<int, int> pll;
int n, m, T, a[N];
pll p[N];
int res = -1;
int sum[N];
set<int> st;
int _res;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    p[i] = make_pair(a, b);
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + p[i].second;
  for (int i = 1; i <= n; i++) }