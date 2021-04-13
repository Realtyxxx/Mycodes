#include <iostream>

#include "Alist.h"
#include "Listf.h"
using namespace std;
#define defaultSize 1001

int main() {
  AList<char> my_list;
  string str;
  cin >> str;
  for (int i = 0; i < int(str.length()); i++) {
    my_list.append(str[i]);
  }
  if (str.length() == 0 || str.length() == 1) {
    cout << "yes";
    return 0;
  }
  int left = 0;
  int right = my_list.length() - 1;
  bool isPalindrome = true;
  while (left < right) {
    if (my_list[left] != my_list[right]) {
      isPalindrome = false;
      break;
    }
    left++;
    right--;
  }
  cout << (isPalindrome ? "yes" : "no") << endl;
  return 0;
}