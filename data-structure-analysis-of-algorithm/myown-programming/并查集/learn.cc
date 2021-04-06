// https://blog.csdn.net/stpeace/article/details/46506861

// tao ge的并查集

#include <iostream>
using namespace std;

#define N 1000
int leader[N + 1] = {0};  // 先搞一个充分大的数组

// 初始化
void setLeader() {
  int i = 1;
  for (i = 1; i <= N; i++) {
    leader[i] = i;  // 初始化时， 将自己初始化为自己的领导
  }
}

// 查找领导， 看看究竟是谁(实际上， 还可以进行路径压缩优化)
int findLeader(int n) {
  int r = n;
  while (leader[r] != r) {
    r = leader[r];  // 没找到的话， 一直往上找
  }

  return r;
}

// 将两个领导带领的团队融合, 从此， leaderX和leaderY建立了新的统一战线，
// 是一个大家庭团队了
void uniteSet(int leaderX, int leaderY) {
  leader[leaderX] = leaderY;  // leader[leaderY] = leaderX;
}

// 输入数组, 每一行表示一个集合关系， 比如第一行表示3和4属于一个集合团队
int input[18] = {
    3, 4, 4, 2, 7, 6, 5, 1, 3, 9, 11, 8, 6, 10, 9, 13, 11, 12,
};

// 测试数组， 测试每行的两个整数是否属于同一个大的家庭团队
int test[24] = {
    3, 2, 9, 4, 7,  10, 6, 7, 13, 4,  8, 12,
    //YES
    6, 9, 4, 7, 11, 10, 1, 2, 12, 13, 7, 13,
    //NO
};

int main() {
  int numberOfSets = 13;  // 总共有13个元素， 即1, 2, 3, 4, ...., 13

  // 初始化领导
  setLeader();

  int i = 0;
  int j = 0;
  int n = sizeof(input) / sizeof(input[0]) / 2;
  for (j = 0; j < n; j++) {
    int u = input[i++];
    int v = input[i++];

    // 找领导
    u = findLeader(u);
    v = findLeader(v);

    // 领导不相等， 则融合着两个团队， 合二为一
    if (u != v) {
      uniteSet(u, v);
      numberOfSets--;
    }
  }

  i = 0;
  n = sizeof(test) / sizeof(test[0]) / 2;
  for (j = 0; j < n; j++) {
    int u = test[i++];
    int v = test[i++];

    // 找领导
    u = findLeader(u);
    v = findLeader(v);

    // 如果领导不相同， 则不属于一个团队； 如果两个领导相同， 则肯定属于一个团队
    if (u != v) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  // 其实， 经合并后， 最后的集合是4个：
  // {3, 4, 2, 9, 13}, {7, 6, 10,}, {5, 1}, {11, 8, 12}
  cout << numberOfSets << endl;

  return 0;
}