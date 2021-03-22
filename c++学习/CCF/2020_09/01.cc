#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
typedef struct {
  int idx;
  int x;
  int y;
} pos;

int n, px, py;

bool comp(const pos& a, const pos& b) {
  return ((a.x - px) * (a.x - px) + (a.y - py) * (a.y - py)) <
         ((b.x - px) * (b.x - px) + (b.y - py) * (b.y - py));
}

int main() {
  std::cin >> n >> px >> py;
  pos* p = new pos[n];
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i].x >> p[i].y;
    p[i].idx = i;
  }

  std::sort(p + 1, p + n, comp);

  for (int i = 1; i <= 3; ++i) {
    std::cout << p[i].idx << std::endl;
  }
  delete[] p;
  return 0;
}