#include <iomanip>
#include <iostream>
#include <vector>

// #include "Graphm.h"

using namespace std;

void dij(vector<vector<double> >& m, vector<double>& b, int a);
double get8(double);

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<double> > poundage(n + 1, vector<double>(n + 1, 0));
  int a, b;
  double c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    poundage[a][b] = 1 - c / 100;
  }
  int from, to;
  cin >> from >> to;
  vector<double> d(n + 1, 0);
  dij(poundage, d, from);
  double ans = 100 / poundage[from][to];
  ans = get8(ans);
  printf("%.8f\n", ans);

  return 0;
}

void dij(vector<vector<double> >& m, vector<double>& b, int a) {
  int n = b.size();
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      m[a][j] = max(m[a][j], m[a][i] * m[i][j]);
    }
  }
}

double get8(double x) {
  return (long long)(x * 1e8) / (1e8);
}