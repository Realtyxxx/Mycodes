/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (70.61%)
 * Likes:    483
 * Dislikes: 0
 * Total Accepted:    166.4K
 * Total Submissions: 235.3K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 *
 *
 *
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 *
 * 示例:
 *
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 0)
      return {};
    vector<int> temp;
    vector<vector<int>> ans;
    temp.push_back(1);
    ans.push_back(temp);
    while (--numRows) {
      vector<int> curr;
      int size = temp.size();
      curr.push_back(1);
      for (int i = 1; i < size; i++) {
        curr.push_back(temp[i] + temp[i - 1]);
      }
      curr.push_back(1);
      ans.push_back(curr);
      temp.swap(curr);
    }
    return ans;
  }
};
// @lc code=end
