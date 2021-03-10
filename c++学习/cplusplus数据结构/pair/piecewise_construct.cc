// piecewise_construct example
// This constant value is passed as the first argument to construct a pair
// object to select the constructor form that constructs its members in place by
// forwarding the elements of two tuple objects to their respective constructor.
//就是将参数分别用他们自己的构造函数构造

// forward_as_tuple将此常量值作为构造对对象的第一个参数传递，以选择构造函数形式，
//该形式通过将两个元组对象的元素转发到其各自的构造函数来就地构造其成员。

#include <iostream>  //std::cout
#include <string>    //std::string
#include <tuple>     //std::forward_as_tuple
#include <utility>   //std::pair,std::piecewise_construct
#include <vector>    //std::vector

int main() {
  std::pair<std::string, std::vector<int> > foo(std::piecewise_construct,
                                                std::forward_as_tuple("test"),
                                                std::forward_as_tuple(3, 10));
  std::cout << "foo.first: " << foo.first << std::endl;
  std::cout << "foo.second: ";
  for (int& x : foo.second) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}