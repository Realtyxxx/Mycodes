/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (41.39%)
 * Likes:    549
 * Dislikes: 0
 * Total Accepted:    91.3K
 * Total Submissions: 219.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n
 * 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 *
 * 示例 1:
 *
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2:
 *
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    if (rows == 0 || columns == 0)
      return {};
    vector<int> ans;
    int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
    while (left <= right && top <= bottom) {
      for (int column = left; column <= right; ++column) {
        ans.push_back(matrix[top][column]);
      }
      for (int row = top + 1; row <= bottom; ++row) {
        ans.push_back(matrix[row][right]);
      }
      if (left < right && top < bottom) {
        for (int column = right - 1; column > left; --column) {
          ans.push_back(matrix[bottom][column]);
        }
        for (int row = bottom; row > top; --row) {
          ans.push_back(matrix[row][left]);
        }
      }
      top++;
      left++;
      right--;
      bottom--;
    }
    return ans;
  }
};
// @lc code=end
