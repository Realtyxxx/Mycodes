#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1 = "Energy-Aware Device Drivers for Embedded Operating Systems";
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == ' ') s1[i] = '_';
  }
	cout << s1 << endl;
	return 0;
}