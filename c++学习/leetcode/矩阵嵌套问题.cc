#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int N = 10007, M = 5e3 + 7, maxn = 1007;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;
PII pos[N];
int f[N];  //表示以x为起点的最长路径长度
int g[N][N];

int dp(int x) {
  int& ans = f[x];
  if (ans > 0) return ans;
  ans = 1;  //作为起点
  for (int y = 0; y < n; ++y) {
    if (g[x][y]) ans = max(ans, dp(y) + 1);
  }
  return ans;
}

void print_ans(int x) {
  printf("%d ", x);
  for (int y = 0; y < n; ++y)
    if (g[x][y] && f[x] == f[y] + 1) {
      print_ans(y);
      break;
    }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &pos[i].x, &pos[i].y);
    if (pos[i].x > pos[i].y) swap(pos[i].x, pos[i].y);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (pos[i].x < pos[j].x && pos[i].y < pos[j].y) {
        g[i][j] = 1;
      }
    }
  }
  int ans = -1;
  int max_id = 0;
  for (int i = 0; i < n; ++i) {
    if (dp(i) > ans) {
      ans = dp(i);
      max_id = i;
    }
  }
  printf("%d\n", ans);
  print_ans(max_id);
  return 0;
}
