#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

bool isPrime(int n){
  for (int i = 2;i < sqrt(n); ++i) {
    if(n % i == 0) return false;
  }
  return true;
}

int main() {
  int num;
  cout << "Input a number to decide if is a prime number" << endl;
  cin >> num;
  bool isPrimeNumber = isPrime(num);
  if(isPrimeNumber) cout << num << "is a prime number";
  else cout << num << "is not a prime number";
  return 0;
}