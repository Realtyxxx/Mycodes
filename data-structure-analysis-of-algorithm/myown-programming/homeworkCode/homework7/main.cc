#include <iostream>
using namespace std;
int main() {
  int result = 0, n;
  cin >> n;
  n /= 10;
  while (n / 5) {
    int i = n / 5;
    result += 7 * i;
    n -= i * 5;
  }
  while (n / 3) {
    int i = n / 3;
    result += 4 * i;
    n %= 3;
  }
  result += n;
  cout << result;
  return 0;
}