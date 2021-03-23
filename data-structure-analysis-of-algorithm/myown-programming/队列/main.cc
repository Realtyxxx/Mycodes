#include <iostream>

#include "aQueue.hpp"
#include "queueF.hpp"

AQueue<char> my_queue;

int main() {
  int alphabetCount = 0;
  int numberCount = 0;
  int otherCount = 0;

  std::string str;
  std::cin >> str;

  for (int i = 0; i < (int)str.size(); i++) {
    // if (temp != '\0' || temp != '\n') {
    char temp = str[i];
    if ((temp <= 'Z' && temp >= 'A') || (temp >= 'a' && temp <= 'z')) {
      alphabetCount++;
      my_queue.enqueue(temp);
    }
    if (temp >= '0' && temp <= '9') {
      numberCount++;
    }
    if (!(temp <= 'Z' && temp >= 'A') && !(temp >= 'a' && temp <= 'z') &&
        !(temp <= '9' && temp >= '0')) {
      otherCount++;
      my_queue.enqueue(temp);
    }
    // }
  }
  std::cout << alphabetCount << " " << numberCount << " " << otherCount
            << std::endl;
  while(my_queue.length()){
    std::cout<<my_queue.frontValue();
    my_queue.dequeue();
  }

  return 0;
}