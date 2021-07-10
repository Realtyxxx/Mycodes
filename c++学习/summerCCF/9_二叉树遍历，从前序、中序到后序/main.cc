#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

#include "./_mytree.h"

using namespace std;

int                      pre_idx;
unordered_map<char, int> idx_map;

myNode* helper(int in_left, int in_right, string inorder, string preorder) {
  //如果没有节点构造二叉树，就结束
  if (in_left > in_right) {
    return nullptr;
  }
  //选择pre_idx位置的元素作为当前子树的根结点
  int     root_val = preorder[pre_idx];
  myNode* root     = new myNode(root_val);
  //根据root所在位置分成左右子树
  int index = idx_map[root_val];

  //下标减一
  pre_idx++;
  //构造左子树
  root->setLeft(helper(in_left, index - 1, inorder, preorder));
  //构造右子树
  root->setRight(helper(index + 1, in_right, inorder, preorder));
  return root;
}

myNode* buildTree(string inorder, string preorder) {
  //从后续遍历的最后一个元素开始
  pre_idx = 0;
  //建立（元素，下标）键值对的哈希表
  int idx = 0;
  for (auto& val : inorder) {
    idx_map[val] = idx++;
  }
  return helper(0, (int)inorder.size() - 1, inorder, preorder);
}

void postOrder(myNode* node, string& s) {
  if (node->getLeft())
    postOrder(node->getLeft(), s);
  if (node->getRight())
    postOrder(node->getRight(), s);
  s.push_back(node->getValue());
}

int main() {
  string         inorder, preorder;
  int            size;
  vector<string> ans;
  while (cin >> size && size != 0) {
    string tmp;
    cin >> preorder >> inorder;
    myNode* root = buildTree(inorder, preorder);
    // vector<int> ans;  // 层序遍历；
    postOrder(root, tmp);
    ans.push_back(tmp);
  }
  for (auto s : ans) {
    cout << s << endl;
  }
  return 0;
}