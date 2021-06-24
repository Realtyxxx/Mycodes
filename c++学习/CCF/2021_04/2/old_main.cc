#include <assert.h>
#include <iostream>
#include <memory>
class solution {
 private:
  int n, L, r, t;
  int *A_array;

 public:
  ~solution() {
    assert(A_array != nullptr);
    delete[] A_array;
  }

  void getargs() {
    std::cin >> n >> L >> r >> t;
    A_array = new int[n * n];
    for (int i = 0; i < n * n; i++) std::cin >> A_array[i];
  }

  void stupid_way() {
    // std::cout << "r = " << r << std::endl << "t = " << t << std::endl;
    int count = 0;
    for (int i = 0; i < n * n; i++) {
      int x = i % n, y = i / n;
      double sum = 0;
      int left = (x - r >= 0 ? x - r : 0), right = (x + r < n ? x + r : n - 1), up = (y - r >= 0 ? y - r : 0), down = (y + r < n ? y + r : n - 1);
      for (int col = left; col <= right; col++) {
        for (int row = up; row <= down; row++) {
          sum += A_array[n * row + col];
        }
      }
      int divisor = (right - left + 1) * (down - up + 1);
      /* std::cout << "sum =  " << sum << " average = "
                << (sum / float((right - left + 1) * (down - up + 1)))
                << std::endl;
       */
      if (sum / divisor - t <= 0) count++;
    }
    std::cout << count;
  }
  void smart_way() {}
};

int main() {
  solution *my = new solution;
  my->getargs();
  my->stupid_way();
  delete my;
  return 0;
}