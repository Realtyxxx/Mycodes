#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;
  str[str.size()/2] = '\0';
  cout << str << endl;
  return 0;
}
