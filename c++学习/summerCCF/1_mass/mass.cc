// 3 incorrect
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int enough, tmp, num;

  // vector<int> ans;
  bool        getAns;

  while (cin >> num && num != 0) {
    enough = num / 2;
    unordered_map<int, int> cnt;
    getAns     = false;
    int maxCnt = 1;
    cin >> tmp;
    int maxNum = tmp;
    cnt[tmp]   = 1;
    for (int i = 0; i < num - 1; i++) {
      cin >> tmp;
      if (!getAns) {
        if (cnt[tmp] >= 1) {
          cnt[tmp]++;
          if (cnt[tmp] > maxCnt) {
            maxNum = tmp;
            maxCnt = cnt[tmp];
          }
          if (cnt[tmp] >= enough) {
            // ans.push_back(tmp);
            getAns = true;
          }
        } else {
          cnt[tmp] = 1;
          if (cnt[tmp] > maxCnt) {
            maxNum = tmp;
            maxCnt = cnt[tmp];
          }
        }
      }
    }
    // ans.push_back(maxNum);
    cout << maxNum << endl;
  }

  // for (int i = 0; i < (int)ans.size(); i++) {
  //   cout << ans[i] << endl;
  // }

  return 0;
}