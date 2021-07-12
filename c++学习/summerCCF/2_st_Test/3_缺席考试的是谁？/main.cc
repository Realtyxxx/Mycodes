#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    unordered_map<string, int> mp;
    for (int i = 0; i < 2 * n - 1; i++) {
      string s;
      cin >> s;
      if (!mp.count(s)) {
        mp.insert(make_pair(s, 1));
      } else {
        mp[s]++;
      }
    }
    for (auto m : mp) {
      if (m.second == 1) {
        cout << m.first << endl;
      }
    }
  }
  return 0;
}