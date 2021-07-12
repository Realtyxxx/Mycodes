#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool match(char s, char c);
int  main() {
  int numOfTest;
  cin >> numOfTest;
  vector<string> test(numOfTest);
  vector<bool>   ans(numOfTest);
  for (int i = 0; i < numOfTest; i++) {
    cin >> test[i];
  }
  for (int i = 0; i < numOfTest; i++) {
    stack<char> tmp;
    for (int j = 0; j < test[i].size(); j++) {
      if (test[i][j] == '<' || test[i][j] == '(' || test[i][j] == '{' || test[i][j] == '[')
        tmp.push(test[i][j]);
      else if (!tmp.empty() && match(tmp.top(), test[i][j]))
        tmp.pop();
      else {
        tmp.push(test[i][j]);
        break;
      }
    }
    if (tmp.empty())
      ans[i] = true;
    else
      ans[i] = false;
  }
  for (auto s : ans)
    if (s)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
}

bool match(char s, char c) {
  return ((s == '<' && c == '>') || (s == '[' && c == ']') || (s == '(' && c == ')') ||
          (s == '{' && c == '}'));
}
