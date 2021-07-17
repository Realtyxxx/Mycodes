#include <iostream>

using namespace std;

int main() {
  int x = 10;
  int y = 23;
  int && r1 = x + y;
  x = 20;
  cout << "x = " << x << " y = " << y << " r1 = " << r1 << endl;
  return 0;
}