#include <algorithm>
#include <iostream>
using namespace std;
struct shu {
  int large;
  int number;
  int order;
  shu() : large(0), number(0), order(0) {
  }
};
bool compare(const shu& right, const shu& left) {
  if (right.number != left.number)
    return right.number > left.number;
  else if (right.order != left.order)
    return right.order < left.order;
  return 0;
}
int main() {
  int n;
  while (cin >> n && n) {
    shu num[10001];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      num[x].large = x;
      num[x].number++;
      num[x].order = i;
    }
    sort(num, num + 10001, compare);
    cout << num[0].large << endl;
  }
  return 0;
}