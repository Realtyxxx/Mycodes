#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool   isAlphabet(char c);
string takeCare(string);
char   getNum(char c);

int main() {
  int n;
  cin >> n;
  unordered_map<string, int> cnt;
  vector<string>             um;
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    string deal = takeCare(tmp);
    deal.insert(3, 1, '-');
    // cout << deal << endl;
    if (!cnt.count(deal)) {
      cnt.insert(make_pair(deal, 1));
      // cout << "runned" << endl;
    } else {
      cnt[deal]++;
    }
    // cout << cnt.count(deal) << endl;
  }
  for (auto l : cnt) {
    if (cnt[l.first] > 1) {
      cout << l.first << " " << l.second << endl;
    }
  }
  return 0;
}

string takeCare(string s) {
  string d;
  int    l = s.length();

  for (int i = 0; i < l; i++) {
    if (s[i] == '-') continue;
    if (isAlphabet(s[i])) {
      d.push_back(getNum(s[i]));
      continue;
    } else {
      d.push_back(s[i]);
    }
  }
  return d;
}

bool isAlphabet(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char getNum(char c) {
  if (isAlphabet(c)) {
    switch (c) {
      case 'A':
      case 'B':
      case 'C':
        return '2';
      case 'D':
      case 'E':
      case 'F':
        return '3';
      case 'G':
      case 'H':
      case 'I':
        return '4';
      case 'J':
      case 'K':
      case 'L':
        return '5';
      case 'M':
      case 'N':
      case 'O':
        return '6';
      case 'P':
      case 'R':
      case 'S':
        return '7';
      case 'T':
      case 'U':
      case 'V':
        return '8';
      case 'W':
      case 'X':
      case 'Y':
        return '9';
    }
  }
  return 0;
}