#include <iostream>
#include <set>

int main() {
  int my_ints[] = {12, 75, 10, 32, 20, 25};

  std::set<int> first(my_ints, my_ints + 3);  //10 12 75
  std::set<int> second(my_ints + 3, my_ints + 6); //20 25 32

  first.swap(second);

  std::cout << "first contains :";
  for (std::set<int>::iterator it = first.begin(); it != first.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
  
  return 0;
}