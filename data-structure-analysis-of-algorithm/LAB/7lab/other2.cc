#include <memory.h>

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1005

vector<int> path[MAX_N];
int visit[MAX_N];
int ans[MAX_N][MAX_N];

void dfs(int a, int b) {
  ans[a][b] = 1;
  ans[b][a] = 1;
  visit[b] = 1;
  for (int j = 0; j < (int)path[b].size(); j++) {
    if (visit[path[b][j]] == 0) {
      dfs(a, path[b][j]);
    }
  }
}

int main() {
  memset(ans, 0, sizeof(ans));
  memset(visit, 0, sizeof(visit));

  int n, m, num = 0;
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    path[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) {
    memset(visit, 0, sizeof(visit));
    dfs(i, i);
  }
  for (int i = 1; i <= n; i++) {
    int j = 1;
    for (; j <= n; j++) {
      if (ans[i][j] == 0) {
        break;
      }
    }
    if (j == n + 1) {
      num++;
    }
  }
  cout << num;
  return 0;
}