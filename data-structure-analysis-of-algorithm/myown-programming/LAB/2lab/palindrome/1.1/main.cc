#include <iostream>

#include "Listf.h"
#include "Llist.h"
using namespace std;

int main() {
  bool isPalindrome = true;
  Llist<char> my_str, reverse;

  // string str;
  // cin >> str;
  // for (char temp : str) {
  //   my_str.append(temp);
  //   reverse.insert(temp);
  // }
  char temp;
  while ((temp = cin.get()) != EOF and temp != '\n') {
    my_str.append(temp);
    reverse.insert(temp);
  }
  my_str.moveToStart();
  reverse.moveToStart();
  for (int i = 0; i < my_str.length(); i++) {
    if (my_str.getValue() != reverse.getValue()) {
      isPalindrome = false;
      break;
    }
    my_str.next();
    reverse.next();
  }

  if (!isPalindrome)
    cout << "no";
  else
    cout << "yes";
  return 0;
}

/*   char *str = (char *)malloc(100 * sizeof(char));
  scanf("%s", str);
  printf("%s", str);
 */