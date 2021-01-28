/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (63.96%)
 * Likes:    757
 * Dislikes: 0
 * Total Accepted:    244.8K
 * Total Submissions: 382.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。
 * （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回其层序遍历结果：
 *
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include "mytree.hpp"

class Solution {
 public:
  vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if (root == NULL) return res;
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q2.push(root);
    while (!q1.empty() || !q2.empty()) {
      q1.swap(q2);
      vector<int> tmp;
      while (!q1.empty()) {
        TreeNode* node = q1.front();
        q1.pop();
        tmp.push_back(node->val);
        if (node->left) q2.push(node->left);
        if (node->right) q2.push(node->right);
      }
      res.push_back(tmp);
    }
    return res;
  }
};
// @lc code=end