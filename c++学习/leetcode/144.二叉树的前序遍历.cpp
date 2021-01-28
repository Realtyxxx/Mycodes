/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (68.92%)
 * Likes:    503
 * Dislikes: 0
 * Total Accepted:    253.1K
 * Total Submissions: 366.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 *
 * 示例 5：
 *
 *
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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

#include "mytree.hpp"

class Solution {
 public:
  vector<int> result;
  // recursion
  void preorder(TreeNode* root) {
    if (root == nullptr) return;
    result.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
    return;
  }
  vector<int> preorderTraversal(TreeNode* root) {
    preorder(root);
    return result;
  }

  // iteration
  vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return result;
    }
    stack<TreeNode*> stk;
    TreeNode* node = root;
    while (!stk.empty() || node != nullptr) {
      while (node != nullptr) {
        result.emplace_back(node->val);
        stk.emplace(node);
        node = node->left;
      }
      node = stk.top();
      stk.pop();
      node = node->right;
    }
    return result;
  }

  // morris‘god-lever traversal!!!!
  vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) return result;

    TreeNode *cur = root, *mostRight = nullptr;

    while (cur != nullptr) {
      mostRight = cur->left;
      if (mostRight != nullptr) {
        while (mostRight->right != nullptr && mostRight->right != cur) {
          mostRight = mostRight->right;
        }
        if (mostRight->right == nullptr) {
          result.emplace_back(cur->val);
          mostRight->right = cur;
          cur = cur->left;
          continue;
        } else {
          mostRight->right = nullptr;
        }
      } else {
        result.emplace_back(cur->val);
      }
      cur = cur->right;
    }
    return result;
  }
};

// @lc code=end
