#include <bits/stdc++.h>

int main() {
  int n, m, L, temp;
  std::cin >> n >> m >> L;
  int *h = (int *)malloc(L * sizeof(int));
  for (int i = 0; i < n * m; i++) {
    std::cin >> temp;
    h[temp]++;
  }
  for (int i = 0; i < L; i++) std::cout << h[i] << " ";
}