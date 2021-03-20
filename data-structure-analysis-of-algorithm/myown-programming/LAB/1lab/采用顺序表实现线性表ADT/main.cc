#include <iostream>

#include "Alist.h"
#include "Listf.h"

AList<char> my_list;

int main() {
  int alphabetCount;
  int numberCount;
  int otherCount;
  while (1) {
    char temp;
    std::cin >> temp;
    if (temp != '\0' || temp != '\n') {
      if ((temp <= 'Z' && temp >= 'A') || (temp >= 'a' && temp <= 'z')) {
        alphabetCount++;
        my_list.insert(temp);
      }
      if ((temp > 'Z' || temp < 'A') && (temp < 'a' && temp > 'z') &&
          (temp > '9' || temp < '0')) {
        otherCount++;
        my_list.insert(temp);
      }
      if (temp <= '9' || temp >= '0') {
        numberCount++;
      }
    } else
      break;
  }
  std::cout << alphabetCount << " " << numberCount << " " << otherCount
            << std::endl;
  for (my_list.moveToStart(); my_list.length() > 0;) {
    std::cout << my_list.getValue();
    my_list.remove();
  }
  
  return 0;
}