#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
typedef struct {
  int idx;
  double distance;
} pos;

bool comp(const pos& a, const pos& b) { return a.distance < b.distance; }

int main() {
  int n, px, py;
  std::cin >> n >> px >> py;
  pos* p = new pos[n];
  int x, y;
  for (int i = 1; i <= n; ++i) {
    std::cin >> x >> y;
    p[i].distance = double((x - px) * (x - px) + (y - py) * (y - py));
    p[i].idx = i;
  }

  std::sort(p + 1, p + n, comp);

  for (int i = 1; i <= 3; ++i) {
    std::cout << p[i].idx << std::endl;
  }
  delete[] p;
  return 0;
}
