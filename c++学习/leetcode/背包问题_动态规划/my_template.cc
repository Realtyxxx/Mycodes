#include <iostream>
#include <vector>
using namespace std;

#define WEIGHT_NUMS 3
#define VALUE_NUMS 4
int weight[]  = {1, 3, 4};
int value[]   = {15, 20, 30};
int bagWeight = 4;

vector<vector<int> > dp(WEIGHT_NUMS, vector<int>(bagWeight + 1, 0));
vector<int>          dp1(bagWeight + 1, 0);

void bag() {
  // vector<vector<int> > dp(WEIGHT_NUMS + 1, vector<int>(bagWeight + 1, 0));
  // i means now we are picking the i_th things ,
  // j means when we have j capacity ,we can pick how much value things;
  // dp[i][j] means the walue we pick when i & j;
  for (int j = bagWeight; j >= weight[0]; j--) {
    dp[0][j] = dp[0][j - weight[0]] + value[0];
  }

  for (int i = 1; i < WEIGHT_NUMS; i++) {
    for (int j = 0; j <= bagWeight; j++) {
      if (j < weight[i]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
      }
    }
  }
  cout << dp[WEIGHT_NUMS - 1][bagWeight] << endl;
  // i = 0, 只选择第0个项目的时候的选择；
}
void bag1vec() {
  for (int i = 0; i < WEIGHT_NUMS; i++) {
    for (int j = bagWeight; j >= weight[i]; j--) {
      dp1[j] = max(dp1[j], dp1[j - weight[i]] + value[i]);
    }
  }

  cout << dp1[bagWeight] << endl;
}

void printVec() {
  for (int i = 0; i < WEIGHT_NUMS; i++) {
    for (int j = 0; j <= bagWeight; j++) {
      cout << dp[i][j] << "  ";
    }
    cout << endl;
  }
}

int main() {
  bag1vec();
  // printVec();
  return 0;
}
