#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if (s2.size() == 0) {
    cout << "yes";
    return 0;
  }
  bool contain = false;
  for (int i = 0; i < (int)s1.size(); i++) {
    int j;
    if (s1[i] == s2[0] && s2[i] != '#') {
      for (j = 0; j < (int)s2.size(); j++) {
        if (s1[i + j] != s2[j]) {
          break;
        }
      }
    }
    if (j == s2.size()) {
      cout << "yes";
      contain = true;
      break;
    } else
      continue;
  }
  if (contain == false) cout << "no";
  return 0;
}