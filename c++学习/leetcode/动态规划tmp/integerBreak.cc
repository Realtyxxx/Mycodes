#include <memory.h>
#include <cmath>
#include <iostream>
#include <vector>

class Solution {
 public:
  int integerBreak(int n) {
    if (n <= 2)
      return 1;
    std::vector<int> a(n + 1, 0);
    // a[i]中存储的是数i可以得到的最优解，也因此这个解实际上没有保留它自身
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = i - 1; j >= int(i / 2); j--) {
        //***********方法1:***********
        // a[i] = std::max((i < n ? i : 0), std::max(a[j] * (i - j), a[i]));
        //可以是他自己的乘积或者它的最优子解得到的答案:::::我感觉我暂时没法解释。这个暂时不可取

        //***********方法2***********
        a[i] = std::max(std::max((i < n ? i : 0), a[i - j] * a[j]), a[i]);
        //实际上也是后面理解了前面没有去判断它的的子结构与它自身的大小比较，还需要判断是否比当前的a[i]大

        // std::cout << "a[" << i << "] : " << a[i] << std::endl;
      }
    }
    return a[n];
  }

  // int numTrees(int n) {}
};

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Usage: it should have 2 arguments!";
    return -1;
  }
  int      num = atoi(argv[1]);
  Solution my_solution;
  std::cout << my_solution.integerBreak(num) << std::endl;
  return 0;
}