// make_pair example

#include <iostream>
#include <utility>

int main() {
  std::pair<int, int> foo;
  std::pair<int, int> bar;

  foo = std::make_pair(10, 20);
  bar = std::make_pair(10.5, 'A');

  std::cout << "foo: " << foo.first << ", " << foo.second << std::endl;
  std::cout << "bar: " << bar.first << ", " << bar.second << std::endl;
  return 0;
}