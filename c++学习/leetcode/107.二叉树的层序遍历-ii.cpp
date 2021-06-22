/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Medium (69.07%)
 * Likes:    448
 * Dislikes: 0
 * Total Accepted:    146.5K
 * Total Submissions: 211.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回其自底向上的层序遍历为：
 *
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
#include <vector>
// #include "mytree.hpp"
using namespace std;
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(!root) return {};
    vector<vector<int>> ans;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> layer;
      while (size--) {
        TreeNode* tmp = q.front();
        layer.push_back(tmp->val);
        q.pop();
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
      }
      ans.push_back(layer);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
