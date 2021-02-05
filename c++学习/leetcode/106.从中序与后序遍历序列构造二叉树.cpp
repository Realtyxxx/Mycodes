/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (70.89%)
 * Likes:    443
 * Dislikes: 0
 * Total Accepted:    87.4K
 * Total Submissions: 123K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 *
 * 注意:
 * 你可以假设树中没有重复的元素。
 *
 * 例如，给出
 *
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 *
 * 返回如下的二叉树：
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
//-std=c++11
#include "mytree.hpp"
// #include <unordered_map>  //use unordered_map as hashset
using namespace std;

class Solution1 {
  int post_idx;
  unordered_map<int, int> idx_map;

 public:
  TreeNode* helper(int in_left, int in_right, vector<int>& inorder,
                   vector<int>& postorder) {
    //如果没有节点构造二叉树，就结束
    if (in_left > in_right) {
      return nullptr;
    }
    //选择post_idx位置的元素作为当前子树的根结点
    int root_val = postorder[post_idx];
    TreeNode* root = new TreeNode(root_val);
    //根据root所在位置分成左右子树
    int index = idx_map[root_val];

    //下标减一
    post_idx--;
    //构造右子树
    root->right = helper(index + 1, in_right, inorder, postorder);
    //构造左子树
    root->left = helper(in_left, index - 1, inorder, postorder);
    return root;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    //从后续遍历的最后一个元素开始
    post_idx = (int)postorder.size() - 1;
    //建立（元素，下标）键值对的哈希表
    int idx = 0;
    for (auto& val : inorder) {
      idx_map[val] = idx++;
    }
    return helper(0, (int)inorder.size() - 1, inorder, postorder);
  }
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.size() == 0) return nullptr;
    auto root = new TreeNode(postorder.back());
    auto s = stack<TreeNode*>();
    s.push(root);
    int inorderIndex = inorder.size() - 1;
    //后序遍历每次压栈直接成为右儿子，中序遍历对比栈中顶部元素，，（先对比处理，再压栈）
    for (int i = int(postorder.size()) - 2; i >= 0; --i) {
      //定义节点和当前插入值，
      int postorderVal = postorder[i];
      auto node = s.top();

      if (node->val != inorder[inorderIndex]) {
        node->right = new TreeNode(postorderVal);
        s.push(node->right);
      }
      else {
        while (!s.empty() && s.top()->val == inorder[inorderIndex]) {
          node = s.top();
          s.pop();
          inorderIndex--;
        }
        node->left = new TreeNode(postorderVal);
        s.push(node->left);
      } 
    }
    return root;
  }
};
// @lc code=end
