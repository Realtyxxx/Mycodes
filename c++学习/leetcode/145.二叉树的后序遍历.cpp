/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Medium (73.86%)
 * Likes:    511
 * Dislikes: 0
 * Total Accepted:    182.3K
 * Total Submissions: 246.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 *
 * 示例:
 *
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * 输出: [3,2,1]
 *
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// #include "mytree.hpp"
// -std=c++11
class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == nullptr)
      return result;
    stack<TreeNode *> stk;
    TreeNode *node = root;
    stk.emplace(node);
    while (!stk.empty()) {
      node = stk.top();
      stk.pop();
      result.emplace_back(node->val);
      if (node->left)
        stk.emplace(node->left);
      if (node->right)
        stk.emplace(node->right);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
