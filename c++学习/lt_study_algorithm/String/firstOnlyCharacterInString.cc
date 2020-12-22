#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    if (s.empty()) return -1;
    if (s.size() == 1) return 0;
    int hashmap[256] = {0};
    for (int i = 0; i < s.size(); i++) {
      hashmap[s[i]] += 1;
    }
    for (int i = 0; i < s.size(); i++) {
      if (hashmap[s[i]] == 1) return i;
    }
    return -1;
  }
};


int main() {
  string input;
  cin >> input;
  Solution tyx;
  cout << tyx.firstUniqChar(input)<<endl;
  return 0;
}