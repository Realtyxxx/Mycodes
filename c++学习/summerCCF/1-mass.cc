#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int enough, tmp, num;

  vector<int> ans;
  bool        getAns;

  cin >> num;

  while (num != 0) {
    enough = num / 2;
    unordered_map<int, int> cnt;
    getAns     = false;
    int maxCnt = 0;
    int maxNum;
    for (int i = 0; i < num; i++) {
      cin >> tmp;
      if (!getAns) {
        if (cnt[tmp] >= 1) {
          cnt[tmp]++;
          if (cnt[tmp] >= maxCnt) {
            maxNum = tmp;
            maxCnt = cnt[tmp];
          }
          if (cnt[tmp] >= enough) {
            ans.push_back(tmp);
            getAns = true;
          }
        } else {
          cnt[tmp] = 1;
        }
      }
    }
    if (!getAns) {
      ans.push_back(maxNum);
    }
    cin >> num;
  }
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}