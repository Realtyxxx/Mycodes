#include <iostream>
using namespace std;
int answer;
void traceback(int left, int &answer) {
  if (left == 0) {
      answer+=1;
    return;
  }
  if (left) {
    traceback(left - 1, answer);
  }
  if (left >= 2) {
    traceback(left - 2, answer);
  }
}


int climbStairs(int n) {
  answer = 0;
  traceback(n, answer);
  return answer;
}

int main() {
  cout << "Please enter the number of stails" << endl;
  int n = 0;
  cin >> n;
  climbStairs(n);
  cout << answer << endl;
  return 0;
}