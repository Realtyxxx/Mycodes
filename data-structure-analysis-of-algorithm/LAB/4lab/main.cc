#include <iostream>
#include <stack>
#include <string>
#define INITIAL 0
#include "_charmytree.h"
using namespace std;

myNode* makeTree(string s);
bool contain(myNode* n1, myNode* n2);
bool equal(myNode* n1, myNode* n2);
void preOrder(myNode* root);
// void printTree(myNode* root);
// void printTree(myNode* root, int level);

int main() {
  string s1;
  string s2;
  cin >> s1 >> s2;
  myNode* node1 = makeTree(s1);
  myNode* node2 = makeTree(s2);

  // preOrder(node1);
  // cout << endl;
  // preOrder(node2);
  // cout << endl;

  if (contain(node1, node2))
    cout << "yes";
  else
    cout << "no";
  return 0;
}

myNode* makeTree(string s) {
  myNode* root = new myNode(s[0]);
  // cout << 0 << " " << s[0] << endl;
  myNode* prev = root;  //为了从左儿子到右儿子而保留父亲
  root->left = new myNode(INITIAL, nullptr, nullptr, root);  //预先增加叶子节点
  root->right = new myNode(INITIAL, nullptr, nullptr, root);
  myNode* curr = root->left;
  for (int i = 1; i < s.size(); i++) {
    // cout << i << " " << s[i] << endl;
    if (s[i] != '#') {
      curr->setValue(s[i]);
      curr->left = new myNode(INITIAL, nullptr, nullptr, curr);
      curr->right = new myNode(INITIAL, nullptr, nullptr, curr);
      prev = curr;
      curr = curr->left;
    } else if (s[i] == '#') {
      int count = 0;
      while (i < s.size() && s[i++] == '#') {
        count++;
      }
      if (count >= 1 && s[i - 1] != '#') i -= 2;
      switch (count) {
        case 1:
          curr = prev->right;
          curr->setValue(s[i]);
          prev = curr;
          prev->left = new myNode(INITIAL, nullptr, nullptr, prev);
          prev->right = new myNode(INITIAL, nullptr, nullptr, prev);
          curr = prev->left;
          break;

          // case 2:
          //   prev = prev->father;
          //   // curr = prev->right = new myNode(s[i], nullptr, nullptr, prev);
          //   curr = prev->right;
          //   curr->setValue(s[i]);
          //   curr->left = new myNode(INITIAL, nullptr, nullptr, curr);
          //   curr->right = new myNode(INITIAL, nullptr, nullptr, curr);
          // break;

        default:
          count = count - 1;
          while (count--) {
            if (prev->father == nullptr) break;
            prev = prev->father;
          }
          // curr = prev->right = new myNode(s[i], nullptr, nullptr, prev);
          if (prev->right == curr->father) {
            prev = prev->father;
          }
          curr = prev->right;
          // if (curr->getValue() == INITIAL) cout << "yes" << endl;
          curr->setValue(s[i]);
          curr->left = new myNode(INITIAL, nullptr, nullptr, curr);
          curr->right = new myNode(INITIAL, nullptr, nullptr, curr);
          prev = curr;
          curr = curr->left;
      }
    }
  }

  return root;
}

bool contain(myNode* node1, myNode* node2) {
  if (node1 == nullptr) return false;
  // cout << node1->E << endl;
  if (node1->E == node2->E) return equal(node1, node2);
  return contain(node1->left, node2) || contain(node1->right, node2);
}

bool equal(myNode* node1, myNode* node2) {
  if (node2 == nullptr)
    return true;
  else if (node1 == nullptr && node2 != nullptr)
    return false;
  return (node1->getValue() == node2->getValue()) &&
         equal(node1->left, node2->left) && equal(node1->right, node2->right);
}

// void printTree(myNode* root) { printTree(root, 0); }
// void printTree(myNode* root, int level) {
//   cout << (' ' * (8 - level));
//   if (root != nullptr) cout << root->E;
//   cout << endl;
//   if (root->left) {
//     printTree(root->left, level + 1);
//   }
//   if (root->right) {
//     printTree(root->left, level - 1);
//   }
// }
void preOrder(myNode* root) {
  if (root == nullptr) {
    cout << '#';
    return;
  }
  if (root != nullptr) cout << root->E;
  preOrder(root->left);
  preOrder(root->right);
}