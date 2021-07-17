#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
 public:
  void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    int n = A.size();
    move(n, A, B, C);
    return;
  }

  void move(int n, vector<int>& x, vector<int>& y, vector<int>& z) {
    if (n == 1) {
      z.push_back(x.back());
      x.pop_back();
      return;
    }
    move(n - 1, x, z, y);
    z.push_back(x.back());
    x.pop_back();
    move(n - 1, y, x, z);
  }
};

int main(int argc, char* argv[]) {
  int COUNT = atoi(argv[1]);

  vector<int> A(COUNT);
  vector<int> B;
  vector<int> C;
  Solution    s;

  auto start = std::chrono::steady_clock::now();
  s.hanota(A, B, C);
  auto end = std::chrono::steady_clock::now();
  cout << std::chrono::duration<double>(end - start).count() << " s " << endl;
  return 0;
}