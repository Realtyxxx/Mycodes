#include <memory.h>

#include <iostream>
#include <vector>

#define MAXNUM 1000
using namespace std;

//结构体矩形，包含长和宽
struct rectangle {
  int x;
  int y;
};

int longest[MAXNUM];
rectangle** rectangleSets;
int* nums;

// contain(a,b)  : a contain b 创建的包含关系
bool contain(const rectangle& a, const rectangle& b) {
  if ((a.x > b.x && a.y > b.y) || (a.x > b.y && a.y > b.x)) return true;
  return false;
}

int dp(int x, int size, vector<vector<bool> >& tmp);

int getAns(int num, rectangle* m, int size);

int main() {
  int ans = 0;
  int num_sets;
  //读入组数
  cin >> num_sets;
  //初始化组数
  nums = new int[num_sets];
  rectangleSets = new rectangle*[num_sets];
  for (int i = 0; i < num_sets; i++) {
    cin >> nums[i];
    rectangleSets[i] = new rectangle[nums[i]];
  }
  //读数据
  for (int i = 0; i < num_sets; i++) {
    for (int j = 0; j < nums[i]; j++) {
      cin >> rectangleSets[i][j].x >> rectangleSets[i][j].y;
      // cout << "runned" << endl;
    }
  }
  for (int i = 0; i < num_sets; i++) {
    ans = getAns(i, rectangleSets[i], nums[i]);
    // cout << "set " << i << " : " << ans << endl;
    cout << ans;
  }

  // clean trash
  for (int i = 0; i < num_sets; i++) {
    delete rectangleSets[i];
  }
  delete rectangleSets;

  return 0;
}

int getAns(int num, rectangle* m, int size) {
  vector<vector<bool> > tmp(size, vector<bool>(size));
  int ans = -1;
  memset(longest, MAXNUM, sizeof(int));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      tmp[i][j] = contain(m[i], m[j]);
    }
  }

  for (int i = 0; i < size; i++) {
    longest[i] = dp(i, size, tmp);
    ans = (ans >= longest[i] ? ans : rectangle longest[i]);
  }

  return ans;
}

int dp(int x, int size, vector<vector<bool> >& tmp) {
  int& ans = longest[x];
  if (ans > 0) return ans;
  ans = 1;  // 起点
  for (int y = 0; y < size; y++) {
    // cout << tmp[x][y] << " ";
    if (tmp[x][y]) {
      // cout << "in" << endl;
      ans = max(ans, dp(y, size, tmp) + 1);
      // cout << ans;
    }
  }
  return ans;
}