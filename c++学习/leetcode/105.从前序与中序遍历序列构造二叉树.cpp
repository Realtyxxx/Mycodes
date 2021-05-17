/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.68%)
 * Likes:    1038
 * Dislikes: 0
 * Total Accepted:    193.7K
 * Total Submissions: 277.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 *
 * 注意:
 * 你可以假设树中没有重复的元素。
 *
 * 例如，给出
 *
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 *
 * 返回如下的二叉树：
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
#include <iostream>
#include <unordered_map>
#include <vector>

// #include "mytree.hpp"
using namespace std;

// class Solution {
//  public:
//   int idx = 0;
//   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int left,
//                       int right) {
//     int n = inorder.size(), midnum;
//     if (left > right || idx > n - 1) return nullptr;

//     while (idx < n) {
//       for (int i = left; i <= right; i++) {
//         if (inorder[i] == preorder[idx]) {
//           midnum = i;
//           break;
//         }
//       }
//       idx++;
//       if (preorder[idx - 1] == inorder[midnum]) break;
//     }
//     TreeNode* root = new TreeNode(preorder[idx - 1]);
//     root->left = buildTree(preorder, inorder, left, midnum - 1);
//     root->right = buildTree(preorder, inorder, midnum + 1, right);
//     return root;
//   }

//   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//     return buildTree(preorder, inorder, 0, preorder.size() - 1);
//   }
// };
class Solution {
 public:
  unordered_map<int, int> index;
  TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder,
                        int preorder_left, int preorder_right, int inorder_left,
                        int inorder_right) {
    if (preorder_left > preorder_right) {
      return nullptr;
    }
    int preorder_root = preorder_left;
    int inorder_root = index[preorder[preorder_root]];
    TreeNode* root = new TreeNode(inorder[inorder_root]);
    int size_left_subtree = inorder_root - inorder_left;
    root->left = myBuildTree(preorder, inorder, preorder_left + 1,
                             preorder_left + size_left_subtree, inorder_left,
                             inorder_root - 1);
    root->right =
        myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1,
                    preorder_right, inorder_root + 1, inorder_right);
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    for (int i = 0; i < n; i++) {
      index[inorder[i]] = i;
    }
    return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};
// @lc code=end
