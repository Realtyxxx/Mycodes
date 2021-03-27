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
#include <bits/stdc++.h>
// using namespace std;
// #include "mytree.hpp"

// class Solution {
//  public:
//   vector<vector<int> > levelOrder(TreeNode* root) {
//     vector<vector<int> > ans;
//     pre(root, 0, ans);
//     return ans;
//   }
//   void pre(TreeNode* root, int depth, vector<vector<int> >& ans) {
//     if (!root) return;
//     if (depth >= ans.size()) ans.push_back(vector<int>{});
//     ans[depth].push_back(root->val);
//     pre(root->left, depth + 1, ans);
//     pre(root->right, depth + 1, ans);
//   }
// };
class Solution {
 public:
  vector<vector<int> > levelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int> > res;
    queue<TreeNode*> q;
    q.push(root);
    // BFS
    while (!q.empty()) {
      res.push_back({});

      int num = q.size();
      for (int i = 0; i < num; ++i) {
        auto node = q.front();
        q.pop();

        res.back().push_back(node->val);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    return res;
  }
};
// @lc code=end