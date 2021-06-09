#include <algorithm>
#include <iostream>
#include <vector>

#if (__cplusplus == 201103L)
#include <unordered_map>
#include <unordered_set>
#else
#include <tr1/unordered_map>
#include <tr1/unordered_set>

namespace std {
using std::tr1::unordered_map;
using std::tr1::unordered_set;
}  // namespace std

#endif

#define um unordered_map
#define us unordered_set

#define test 0
using namespace std;

class solution {
  int n = 0;
  int m = 0;
  vector<vector<int> > g;
  vector<us<int> > know;
  vector<int> mark;

 public:
  solution() {
    cin >> n >> m;
    g.resize(n + 1);
    mark.resize(n + 1);
    fill(mark.begin(), mark.end(), 0);
    know.resize(n + 1);

    for (int i = 0; i < m; i++) {
      int a = 0, b = 0;
      cin >> a >> b;
      g[a].push_back(b);  // one way road
    }

#if test
    for (int i = 1; i < (int)g.size(); i++) {
      cout << i << ": " << endl;
      for (int j = 0; j < (int)g[i].size(); j++) {
        cout << g[i][j] << ' ';
      }
      cout << endl;
    }
#endif
  }
  void dfs(int now, int source) {
#if test
    cout << "dfs: " << now << ' ' << source << endl;
#endif
    mark[now] = 1;
    know[now].insert(source);
    know[source].insert(now);
    for (int i = 0; i < (int)g[now].size(); i++) {
      int next = g[now][i];
      if (0 == mark[next]) dfs(next, source);
    }
  }
  void dfs_solve() {
    for (int i = 1; i <= n; i++) {
      dfs(i, i);
      fill(mark.begin(), mark.end(), 0);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
#if test
      cout << know[i].size() << ' ';
#endif
      if (n == (int)know[i].size()) {
        ++res;
      }
    }

#if test
    cout << endl;
#endif
    cout << res << endl;
  }
};

int main() {
  solution s;
  s.dfs_solve();
  return 0;
}
