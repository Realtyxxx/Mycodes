#include <iostream>
#include <stack>
#include <string>
#define INITIAL 0
#include "_charmytree.h"
using namespace std;

myNode* makeTree(string s);
bool    contain(myNode* n1, myNode* n2);
bool    equal(myNode* n1, myNode* n2);
void    preOrder(myNode* root);
// void printTree(myNode* root);
// void printTree(myNode* root, int level);

int main()
{
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

myNode* makeTree(string s)
{
  myNode* root = new myNode(s[0]);
  // cout << 0 << " " << s[0] << endl;

  myNode* prev = root;
  //为了从处理左儿子到需要处理右儿子而保留父亲

  root->setLeft(new myNode(INITIAL, nullptr, nullptr, root));
  root->setRight(new myNode(INITIAL, nullptr, nullptr, root));
  //预先增加叶子节点,预先指定左右节点可以避免之后无法与父亲节点形成对应关系的问题

  myNode* curr = root->getLeft();  //指定下次需要操作的位置处的节点
  for (int i = 1; i < (int)s.size(); i++) {
    // cout << i << " " << s[i] << endl;
    if (s[i] != '#') {  //处理非‘#’字符即，不是空值节点情况
      curr->setValue(s[i]);
      curr->setLeft(new myNode(INITIAL, nullptr, nullptr, curr));
      curr->setRight(new myNode(INITIAL, nullptr, nullptr, curr));
      prev = curr;
      curr = curr->getLeft();
    } else if (s[i] == '#') {  //处理空值节点情况
      int count = 0;           //统计‘#’个数，根据经验处理不通个数时候情况
      while (i < (int)s.size() && s[i++] == '#') {
        count++;
      }
      if (count >= 1 && s[i - 1] != '#') i -= 2;
      //为了防止因为判断直接略过了应有的非‘#’字符，以及陷入死循环
      switch (count) {
        //只有一个#的时候代表此时curr的父亲无左子树，找父亲的右子树
        case 1:
          curr = prev->getRight();
          curr->setValue(s[i]);
          prev = curr;
          prev->setLeft(new myNode(INITIAL, nullptr, nullptr, prev));
          prev->setRight(new myNode(INITIAL, nullptr, nullptr, prev));
          curr = prev->getLeft();
          break;
        //多于一个'#'的情况即需要访问第（count-1)的父亲的右子树了
        default:
          count = count - 1;
          while (count--) {
            if (prev->getFather() == nullptr) break;
            prev = prev->getFather();
            // 因为有的时候会根节点无右子节点，而后面会根据count值向上递归寻找父亲
            // 所以需要处理无右子树情况防止越界访问
          }
          if (prev->getRight() == curr->father) {
            prev = prev->getFather();
          }
          // 循环找父亲
          curr = prev->getRight();
          // if (curr->getValue() == INITIAL) cout << "yes" << endl;
          curr->setValue(s[i]);  //找到该处理的位置，设置值并初始化子节点
          curr->setLeft(new myNode(INITIAL, nullptr, nullptr, curr));
          curr->setRight(new myNode(INITIAL, nullptr, nullptr, curr));
          prev = curr;
          curr = curr->getLeft();
      }
    }
  }

  return root;
}

// 判断是否为包含子树的接口函数
bool contain(myNode* node1, myNode* node2)
{
  if (node1 == nullptr) return false;
  // 递归如果第一个节点为空直接返回否。
  // cout << node1->E << endl;
  if (node1->E == node2->E) return equal(node1, node2);
  // 当遇到树1节点值等于树2节点值时候久调用equal函数，从该节点处进行判断
  return contain(node1->getLeft(), node2) || contain(node1->getRight(), node2);
  // 如果当前节点处值不相同开始递归判断树1的左右子树，并将结果相与，存在子树相同即返回true；
  // 所有判断都不相同就会返回false
}

// 从子树位置判断是否相等
bool equal(myNode* node1, myNode* node2)
{
  if (node2 == nullptr) return true;
  // 当树2为空时即返回true，因为有可能树1为非空为另外子树，但仍然为包含关系
  else if (node1 == nullptr && node2 != nullptr)
    return false;
  // 当树1为空，但树2不为空时候显然不成立包含关系
  return (node1->getValue() == node2->getValue()) && equal(node1->getLeft(), node2->getLeft()) &&
         equal(node1->getRight(), node2->getRight());
  // 前面条件都不成立时候，开始判断该点结果是否相同，以及相应但两个树但左右子树是否相同，并把结果相与，只要有一个节点不同即返回false；
}

// void printTree(myNode* root) { printTree(root, 0); }
// void printTree(myNode* root, int level) {
//   cout << (' ' * (8 - level));
//   if (root != nullptr) cout << root->E;
//   cout << endl;
//   if (root->getLeft()) {
//     printTree(root->getLeft(), level + 1);
//   }
//   if (root->getRight()) {
//     printTree(root->getLeft(), level - 1);
//   }
// }
void preOrder(myNode* root)
{
  if (root == nullptr) {
    cout << '#';
    return;
  }
  // 将空节点输出#
  if (root != nullptr) cout << root->E;
  // 有值节点输出它的值
  preOrder(root->getLeft());
  preOrder(root->getRight());
}
