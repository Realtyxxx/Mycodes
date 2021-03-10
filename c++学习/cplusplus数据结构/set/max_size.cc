#include <iostream>
#include <set>
const int n = 1e5;
int main() {
  int i;
  std::set<int> max;
  if (max.max_size() > n) {
    for (i = 0; i < n; ++i) {
      max.insert(i);
    }
    std::cout << "The sets contains " << i << " elements" << std::endl;
  } else
    std::cout << "It do not have enough place " << std::endl;
  return 0;
}