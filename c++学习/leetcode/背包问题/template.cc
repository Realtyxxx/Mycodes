#include <iostream>
#include <vector>
using namespace std;
// 0-1背包问题母代码(二维)
void bags() {
  vector<int> weight = {1, 3, 4};    //各个物品的重量
  vector<int> value = {15, 20, 30};  //对应的价值
  int bagWeight = 4;                 //背包最大能放下多少重的物品

  // 二维数组：状态定义:dp[i][j]表示从0-i个物品中选择不超过j重量的物品的最大价值
  vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));

  // 初始化:第一列都是0，第一行表示只选取0号物品最大价值
  for (int j = bagWeight; j >= weight[0]; j--) dp[0][j] = dp[0][j - weight[0]] + value[0];

  // weight数组的大小 就是物品个数
  for (int i = 1; i < weight.size(); i++)  // 遍历物品(第0个物品已经初始化)
  {
    for (int j = 0; j <= bagWeight; j++)  // 遍历背包容量
    {
      if (j < weight[i])          //背包容量已经不足以拿第i个物品了
        dp[i][j] = dp[i - 1][j];  //最大价值就是拿第i-1个物品的最大价值
      //背包容量足够拿第i个物品,可拿可不拿：拿了最大价值是前i-1个物品扣除第i个物品的
      //重量的最大价值加上i个物品的价值 不拿就是前i-1个物品的最大价值,两者进行比较取较大的
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
    }
  }
  cout << dp[weight.size() - 1][bagWeight] << endl;
}

// 作者：eh-xing-qing
// 链接：https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。