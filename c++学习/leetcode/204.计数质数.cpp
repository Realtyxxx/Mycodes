/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (35.58%)
 * Likes:    584
 * Dislikes: 0
 * Total Accepted:    118.8K
 * Total Submissions: 313.5K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 *
 *
 * 示例 2：
 *
 * 输入：n = 0
 * 输出：0
 *
 *
 * 示例 3：
 *
 * 输入：n = 1
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 5 * 10^6
 *
 *
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;
//线性筛
class Solution {
public:
  int countPrimes(int n) {
    vector<int> primes;
    vector<int> isprime(n, 1);
    for (int i = 2; i < n; i++) {
      if (isprime[i]) {
        primes.push_back(i);
      }
      for (int j = 0; j < primes.size() && primes[j] * i < n; j++) {
        isprime[i * primes[j]] = 0;
        if (i % primes[j] == 0)
          break;
      }
    }
    return primes.size();
  }
};

//埃氏筛
// class Solution {
//  public:
//   int countPrimes(int n) {
//     vector<int> isprimes(n, 1);
//     int ans = 0;
//     for (int i = 2; i < n; i++) {
//       if (isprimes[i]) {
//         ans += 1;
//         if ((long long)i * i < n) {
//           for (long j = i * i; j < n; j += i) {
//             isprimes[j] = 0;
//           }
//         }
//       }
//     }
//     return ans;
//   }
// };
//枚举
// class Solution {
//  public:
//   bool isprime(int x) {
//     for (int i = 2; i * i <= x; i++) {
//       if (x % i == 0) return false;
//     }
//     return true;
//   }
//   int countPrimes(int n) {
//     int ans = 0;
//     for (int i = 2; i < n; i++) {
//       ans += isprime(i);
//     }
//     return ans;
//   }
// };
// @lc code=end

//线性筛法，未完全弄懂，利用vector记录是否为素数，用另一个vector存储已经遍历到的素数