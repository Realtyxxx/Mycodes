#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num) {
  string ans;
  int divisor;

  divisor = num / 1000;
  num %= 1000;
  if (divisor) ans += 'M' * divisor;

  divisor = num / 900;
  num %= 900;
  if (divisor) ans += "CM";

  divisor = num / 500;
  num %= 500;
  if (divisor) ans += 'L' * divisor;

  divisor = num / 400;
  num %= 400;
  if (divisor) ans += "XC";

  divisor = num / 100;
  num %= 100;
  if (divisor) ans += 'C';

  divisor = num / 90;
  num %= 90;
  if (divisor) ans += "XC";

  divisor = num / 50;
  num %= 50;
  if (divisor) ans += 'L';

  divisor = num / 40;
  num %= 40;
  if (divisor) ans += "XL";

  divisor = num / 10;
  num %= 10;
  if (divisor) ans += 'X' * divisor;

  divisor = num / 9;
  num %= 9;
  if (divisor) ans += "IX";

  divisor = num / 5;
  num %= 5;
  if (divisor) ans += 'V';

  divisor = num / 4;
  num %= 4;
  if (divisor) ans += "IV";

  divisor = num / 1;
  num %= 1;
  if (divisor)
    for (int i = 0; i < divisor; i++) {
      ans += "I";
    }

  return ans;
}
int main() {
  // string str = 'I' * 3;
  // cout << str;
  cout << intToRoman(3);
  return 0;
}