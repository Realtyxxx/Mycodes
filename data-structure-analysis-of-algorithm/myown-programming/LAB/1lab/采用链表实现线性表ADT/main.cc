#include <iostream>

#include "Llist.h"
#include "Listf.h"

Llist<char> my_list;

int main() {
  int alphabetCount = 0;
  int numberCount = 0;
  int otherCount = 0;

  std::string str;
  std::cin >> str;

  for (int i = 0; i < str.size(); i++) {
    // if (temp != '\0' || temp != '\n') {
    char temp = str[i];
    if ((temp <= 'Z' && temp >= 'A') || (temp >= 'a' && temp <= 'z')) {
      alphabetCount++;
      my_list.append(temp);
    }
    if (temp >= '0' && temp <= '9') {
      numberCount++;
    }
    if (!(temp <= 'Z' && temp >= 'A') &&
        !(temp >= 'a' && temp <= 'z') && !(temp <= '9' && temp >= '0')) {
      otherCount++;
      my_list.append(temp);
    }
    // }
  }
  std::cout << alphabetCount << " " << numberCount << " " << otherCount
            << std::endl;
  for (my_list.moveToStart(); my_list.length() > 0;std::cout << my_list.getValue(),my_list.remove()); 

  return 0;
}