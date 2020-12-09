// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//  

// 示例 1:

// 输入: [7,1,5,3,6,4]
// 输出: 7
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 =
// 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。      随后，在第 4
// 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出,
// 这笔交易所能获得利润 = 6-3 = 3 。 示例 2:

// 输入: [1,2,3,4,5]
// 输出: 4
// 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 =
// 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。      注意你不能在第 1 天和第
// 2 天接连购买股票，之后再将它们卖出。  
// 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。 示例 3:

// 输入: [7,6,4,3,1]
// 输出: 0
// 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
//  

// 提示：

// 1 <= prices.length <= 3 * 10 ^ 4
// 0 <= prices[i] <= 10 ^ 4
// 相关标签
// 贪心算法
// 数组

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2zsx1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int l = prices.size();
    if (l == 0) return 0;
    int buy = prices[0], profit = 0;
    bool bought = false;
    int i = 0;
    while (i < l) {
      if (!bought) {
        if (i < l - 1 && prices[i + 1] > prices[i]) {
          buy = prices[i];
          bought = true;
        }
      }
      if (bought) {
        if ((prices[i] > buy && i < l - 1 && prices[i + 1] < prices[i]) ||
            i == l - 1) {
          profit += int(prices[i] - buy);
          bought = false;
        }
      }
      cout << bought << "  " << prices[i] << "  " << i << "  " << profit
           << endl;
      i++;
    }
    return profit;
  }
};

// [1,2,3,4,5]
// [7,2,65,3,6,7,3,5,7,234,6]
// []
// [5,3,2,1]
