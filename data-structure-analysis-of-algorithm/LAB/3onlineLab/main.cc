#include <iostream>
#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>

#include "_mytree.h"
using namespace std;

int post_idx;
unordered_map<int, int> idx_map;

myNode* helper(int in_left, int in_right, vector<int>& inorder,
               vector<int>& postorder) {
  //如果没有节点构造二叉树，就结束
  if (in_left > in_right) {
    return nullptr;
  }
  //选择post_idx位置的元素作为当前子树的根结点
  int root_val = postorder[post_idx];
  myNode* root = new myNode(root_val);
  //根据root所在位置分成左右子树
  int index = idx_map[root_val];

  //下标减一
  post_idx--;
  //构造右子树
  root->setRight(helper(index + 1, in_right, inorder, postorder));
  //构造左子树
  root->setLeft(helper(in_left, index - 1, inorder, postorder));
  return root;
}

myNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  //从后续遍历的最后一个元素开始
  post_idx = (int)postorder.size() - 1;
  //建立（元素，下标）键值对的哈希表
  int idx = 0;
  for (auto& val : inorder) {
    idx_map[val] = idx++;
  }
  return helper(0, (int)inorder.size() - 1, inorder, postorder);
}

int main() {
  int size;
  vector<int> inorder, postorder;
  int temp;
  cin >> size;
  for (int i = 0; i < size; i++) {
    cin >> temp;
    postorder.push_back(temp);
  }
  for (int i = 0; i < size; i++) {
    cin >> temp;
    inorder.push_back(temp);
  }
  myNode* root = buildTree(inorder, postorder);
  // vector<int> ans;  // 层序遍历；
  queue<myNode*> myq;
  myq.push(root);
  while (!myq.empty()) {
    myNode* temp = myq.front();
    myq.pop();
    if (temp->getLeft()) myq.push(temp->getLeft());
    if (temp->getRight()) myq.push(temp->getRight());
    // ans.push_back(temp.getValue());
    cout << temp->getValue() << " ";
  }
  return 0;
}