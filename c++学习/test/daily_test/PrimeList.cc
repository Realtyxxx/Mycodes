#include <math.h>

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int num;
  cout << "Input a number to print the number from 2 to the number if the number is a prime number" << endl;
  cin >> num;
  for (int n = 2; n < num; ++n) {
    bool isPrime = true;
    for (int i = 2; i <= (int)sqrt(n); ++i) {
      if (n % i == 0) {
        isPrime = false;
      }
    }
    if(isPrime)cout << n << " ";
  }
  return 0;
}