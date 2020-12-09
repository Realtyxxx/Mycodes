#include <cstdint>
#include <iostream>
using namespace std;
int main() {
  int *ptr = new int(233);
  uint64_t ptr_addr = reinterpret_cast<uint64_t>(ptr);
  cout << "ptr 的地址: " << hex << ptr << endl
       << "ptr_addr 的值(hex): " << hex << ptr_addr << endl;
  delete ptr;
  return 0;
}
/*
ptr 的地址: 0061E6D8
ptr_addr 的值(hex): 0061e6d8
*/ 