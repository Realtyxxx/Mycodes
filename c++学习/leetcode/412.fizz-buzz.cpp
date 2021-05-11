/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode-cn.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (65.91%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    59.6K
 * Total Submissions: 90.4K
 * Testcase Example:  '1'
 *
 * 写一个程序，输出从 1 到 n 数字的字符串表示。
 *
 * 1. 如果 n 是3的倍数，输出“Fizz”；
 *
 * 2. 如果 n 是5的倍数，输出“Buzz”；
 *
 * 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
 *
 * 示例：
 *
 * n = 15,
 *
 * 返回:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> ans;
    for (int i = 1; i <= n; i++) {
      ans.push_back(judge(i));
    }
    return ans;
  }
  string judge(int num) {
    if (num % 3 == 0 && num % 5 == 0)
      return "FizzBuzz";
    else if (num % 3 == 0)
      return "Fizz";
    else if (num % 5 == 0)
      return "Buzz";
    else {
      // string res;
      // while (num) {
      //   res += (num % 10 + '0');
      //   num /= 10;
      // }
      // reverse(res.begin(), res.end());
      return to_string(num);
    }
  }
};
// @lc code=end
