/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (51.61%)
 * Likes:    506
 * Dislikes: 0
 * Total Accepted:    168.4K
 * Total Submissions: 326K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在
 * 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1,2], targetSum = 0
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [0, 5000] 内
 * -1000
 * -1000
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// #include "mytree.hpp"
class Solution {
 public:
  //   bool hasPathSum(TreeNode* root, int targetSum) {
  //     if(root == nullptr) return false;
  //     if (root->left && root->right)
  //       return check(root->left, targetSum, root->val) ||
  //              check(root->right, targetSum, root->val);
  //     else if(!root->left&&root->right)
  //       return check(root->right, targetSum, root->val);
  //     else if(!root->right&&root->left)
  //     return check(root->left, targetSum, root->val);
  //     else return root->val == targetSum;
  //   }
  //   bool check(TreeNode* curr, int targetSum, int sum) {
  //     if (curr->left && curr->right)
  //       return check(curr->left, targetSum, sum + curr->val) ||
  //              check(curr->right, targetSum, sum + curr->val);
  //     else if (curr->left && !curr->right)
  //       return check(curr->left, targetSum, sum + curr->val);
  //     if (!curr->left && curr->right)
  //       return check(curr->right, targetSum, sum + curr->val);

  //     return targetSum == sum + curr->val;
  //   }
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    if (!root->left && !root->right) return targetSum == root->val;
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
  }
};
// @lc code=end
