#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool match(char in, char out) {
  if ((in == '{' && out == '}') || (in == '[' && out == ']') ||
      (in == '(' && out == ')')||(in == '<'&& out == '>'))
    return true;
  else
    return false;
}

int main() {
  stack<char> myst;
  string in;
  cin >> in;
  if (in.size() == 0) {
    cout << "no";
    return 0;
  }
  for (int i = 0; i < in.length(); i++) {
    if (!myst.empty()) {
      if (match(myst.top(), in[i])) {
        myst.pop();
        continue;
      }
      else myst.push(in[i]);
    }
    else myst.push(in[i]);
  }
  cout << ((myst.size() == 0) ? "yes" : "no") << endl;
  return 0;
}
