#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string str;
  while (getline(cin, str)) {
    // cout << str << endl;
    str += " ";
    string ans;
    int    i = str.length() - 1;
    int    j = i;
    for (; i >= 0; i--) {
      if (str[i] == ' ') {
        ans += str.substr(i + 1, j - i);
        // if (j == str.length() - 1)
        //   ans += " ";
        j = i;
      }
      if (i == 0) {
        ans += str.substr(i, j - i);
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}